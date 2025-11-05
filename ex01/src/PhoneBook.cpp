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

Contact::Contact(void) : index(-1) {
    for (int i = 0; i < 5; i++)
        field_info[i] = "";
}

Contact::~Contact(void) {}

PhoneBook::PhoneBook() : contactCount(0) {}
PhoneBook::~PhoneBook() {}

int     ft_check(int field, std::string value) {
    if (value.empty()) {
        std::cerr << "Error: Field cannot be empty." << std::endl;
        return 1;
    }
    if (field >= 0 && field < 4) { // FirstName, LastName, NickName
        for (size_t i = 0; i < value.length(); i++) {
            if (!isalpha(value[i])) {
                std::cerr << "Error: First Name can only contain alphabetic characters" << std::endl;
                return 1;
            }
        }
    }
    else if (field == 3) { // PhoneNumber
        for (size_t i = 0; i < value.length(); i++) {
            if (!isdigit(value[i])) {
                std::cerr << "Error: Phone Number can only contain digits" << std::endl;
                return 1;
            }
        }
    }
    return 0;
}

void    Contact::setField(int field, const std::string& value)
{
    if (ft_check(field, value))
    //re-prompt
    if (field >= 0 && field < 5)
        field_info[field] = value;
    else
        std::cerr << "Invalid field index" << std::endl;
}

void    PhoneBook::addContact()
{
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