/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:55:37 by kmaeda            #+#    #+#             */
/*   Updated: 2025/12/11 16:55:24 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <iostream>
#include <string>

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
    contactCount++;
    std::cout << "Contact added successfully!" << std::endl;
    return;
}

void    displayContacts() {
    std::cout << " ____________________________________________" << std::endl;
    std::cout << "|                                            |" << std::endl;
    std::cout << "|            MY AWESOME PHONEBOOK            |" << std::endl;
    std::cout << "|____________________________________________|" << std::endl;
    std::cout << "|" << "     Index" << "|" << "First Name" << "|" << " Last Name" << "|" << " Nick Name" << "|" << std::endl;
    std::cout << "|                                         |" << std::endl;
    std::cout << "|                                         |" << std::endl;
    std::cout << "|_____________________________________________|" << std::endl;
}

void    PhoneBook::searchContact() {
    int index;

    if (contactCount == 0) {
        std::cout << "Empty PhoneBook" << std::endl;
        return;
    }

    std::string firstName = contacts[i].getField(Contact::FirstName);
    std::string lastName = contacts[i].getField(Contact::LastName);
    std::string nickName = contacts[i].getField(Contact::NickName);
    displayContacts();
    for (int i = 0; i < PhoneBook::contactCount; i++) {

    }
    std::cout << "Enter index: ";
    std::cin >> index;
    while (!isdigit(index) && (index < 0) && (index > 7)) {
        std::cout << "Not valid index" << std::endl;
        std::cout << "Enter index: ";
    }
}