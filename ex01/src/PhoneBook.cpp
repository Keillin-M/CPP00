/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:55:37 by kmaeda            #+#    #+#             */
/*   Updated: 2025/11/05 01:08:35 by kmaeda           ###   ########.fr       */
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

    for (int i = 0; i < 5; i++) {
        std::cout << "Enter ";
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
        contacts[contactCount % 8].setField(i, input);
    }
    contactCount++;
}

void    displayContacts() {
    std::cout << "____________________________________________" << std::endl;
    std::cout << "|                                           |" << std::endl;
    std::cout << "|      WELCOME TO MY AWESOME PHONEBOOK      |" << std::endl;
    std::cout << "____________________________________________" << std::endl;
    std::cout << "|" << "|""|          |          |" << std::endl;
    Std::cout << "|                                         |" << std::endl;
    std::cout << "|                                         |" << std::endl;
    std::cout << "|_________________________________________|" << std::endl;
}

void    PhoneBook::searchContact() {
    int index;

    if (contactCount == 0) {
        std::cout << "Empty PhoneBook" << std::endl;
        return ;
    }
    contacts[index].getField(0);
    contacts[index].getField(1);
    contacts[index].getField(2);
    displayPhonebook();
    std::cout << "Enter index: ";
    std::cin >> index;
    while (!isdigit(index) && (index < 0) && (index > 7)) {
        std::cout << "Not valid index" << std::endl;
        std::cout << "Enter index: ";
    }
}