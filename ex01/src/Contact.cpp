/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:32:27 by kmaeda            #+#    #+#             */
/*   Updated: 2025/10/24 17:56:08 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <string>

//Initialize contact fields
std::string Contact::field_names[5] = {
    "First Name",
    "Last Name",
    "Nick Name",
    "Phone Number",
    "Darkest Secret"
};

Contact::Contact(void) : index(-1) {
    for (int i = 0; i < 5; i++)
        field_info[i] = "";
}

Contact::~Contact(void) {}

int     Contact::valueCheck(int field, const std::string& value) const {
    if (value.empty()) {
        std::cerr << "Error: Field cannot be empty." << std::endl;
        return 1;
    }
    if (field >= 0 && field < 3) { // FirstName, LastName, NickName
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
    std::string input = value;

    while (valueCheck(field, input)) {
        std::cout << "Please re-enter: ";
        std::getline(std::cin, input);
    }
    if (field >= 0 && field < 5)
        field_info[field] = input;
    else
        std::cerr << "Invalid field index" << std::endl;
}

std::string    Contact::getField(int field) const {
    if (field >= 0 && field < 5)
        return field_info[field];
    return "";
}