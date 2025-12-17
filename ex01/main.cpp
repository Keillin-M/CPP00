/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:22:58 by kmaeda            #+#    #+#             */
/*   Updated: 2025/12/17 12:21:55 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;

	while (1)
	{
	    std::cout << std::endl << " ___________________________________________" << std::endl;
	    std::cout << "|                                           |" << std::endl;
    	std::cout << "|      WELCOME TO MY AWESOME PHONEBOOK      |" << std::endl;
    	std::cout << "|___________________________________________|" << std::endl;
		std::cout << std::endl << "PLEASE, TYPE AN OPTION: ADD, SEARCH OR EXIT" << std::endl;
		std::getline (std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl << "Exiting.. bye!" << std::endl;
			return 0;
		}
		if (input.empty() || (input != "ADD" && input != "SEARCH" && input != "EXIT" 
			&& input != "add" && input != "search" && input != "exit"))
			std::cout << "INVALID ENTRY" << std::endl;
		if (input == "EXIT" || input == "exit") {
			std::cout << "Bye bye!" << std::endl;
			return 0;
		}
		else if (input == "ADD" || input == "add")
			phoneBook.addContact();
		else if (input == "SEARCH" || input == "search")
			phoneBook.searchContact();
		if (std::cin.eof()) {
			std::cout << std::endl << "Exiting.. bye!" << std::endl;
			return 0;
		}
	}
	return 0;
}
