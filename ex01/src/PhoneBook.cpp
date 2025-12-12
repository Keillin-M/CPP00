/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:55:37 by kmaeda            #+#    #+#             */
/*   Updated: 2025/12/12 13:25:53 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

PhoneBook::PhoneBook() : contactCount(0) {}
PhoneBook::~PhoneBook() {}

void    PhoneBook::addContact() {
    std::string input;

    std::cout << "Please enter ";
    for (int i = 0; i < 5; i++) { 
        switch (i) {
            case 0:
                std::cout << "First Name: ";
                break;
            case 1:
                std::cout << "Last Name: ";
                break;
            case 2:
                std::cout << "Nick Name: ";
                break;
            case 3:
                std::cout << "Phone Number: ";
                break;
            case 4:
                std::cout << "Darkest Secret: ";
                break;
        }
        std::getline(std::cin, input);
        if (!contacts[contactCount % 8].setField(i, input)) {
            std::cout << "Failed to add contact" << std::endl;
            return;
        }
    }
    if (contactCount < 8)
        contactCount++;
    std::cout << "Contact added successfully!" << std::endl;
    return;
}


void    PhoneBook::displayContact(int i) {
    std::cout << "|" << "         " << (i + 1) << "|";
    std::string firstName = contacts[i].getField(Contact::FirstName);
    std::string lastName = contacts[i].getField(Contact::LastName);
    std::string nickName = contacts[i].getField(Contact::NickName);
    if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
    else {
        while (firstName.length() < 10)
            firstName = " " + firstName;
    }
    std::cout << firstName << "|";
    if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
    else {
        while (lastName.length() < 10)
            lastName = " " + lastName;
    }
    std::cout << lastName << "|";
    if (nickName.length() > 10)
            nickName = nickName.substr(0, 9) + ".";
    else {
        while (nickName.length() < 10)
            nickName = " " + nickName;
    }
    std::cout << nickName << "|" << std::endl;
}

static void    displayList() {
    std::cout << " ___________________________________________" << std::endl;
    std::cout << "|                                           |" << std::endl;
    std::cout << "|            MY AWESOME PHONEBOOK           |" << std::endl;
    std::cout << "|___________________________________________|" << std::endl;
    std::cout << "|" << "     Index" << "|" << "First Name" << "|" << " Last Name" << "|" << " Nick Name" << "|" << std::endl;
}

void    PhoneBook::getContact(int index) {
    int i = index - 1;

    std::cout << "Contact " << index << " details" << std::endl;
    std::cout << "First Name: " << contacts[i].getField(Contact::FirstName) << std::endl;
    std::cout << "Last Name: " << contacts[i].getField(Contact::LastName) << std::endl;
    std::cout << "Nick Name: " << contacts[i].getField(Contact::NickName) << std::endl;
    std::cout << "Phone Number: " << contacts[i].getField(Contact::PhoneNumber) << std::endl;
    std::cout << "Darkest Secret: " << contacts[i].getField(Contact::DarkestSecret) << std::endl;
}

void    PhoneBook::searchContact() {
    std::string input;
    int index;

    if (contactCount == 0) {
        std::cout << "Empty PhoneBook" << std::endl;
        return;
    }
    displayList();

    int displayCount = (contactCount < 8) ? contactCount : 8;
    for (int i = 0; i < displayCount; i++)
        displayContact(i);
    std::cout << "|___________________________________________|" << std::endl;
    
    while (true) {
        std::cout << "Enter index: ";
        std::getline(std::cin, input);
        
        std::stringstream ss(input);
        if (ss >> index && ss.eof()) {
            if (index >= 1 && index <= contactCount && index <= 8) {
                break;
            }
            std::cout << "Index out of range" << std::endl;
        }
        else {
            std::cout << "Invalid input. Please enter a number." << std::endl;
        }
    }
    
    getContact(index);
}