/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:22:58 by kmaeda            #+#    #+#             */
/*   Updated: 2025/12/12 12:44:36 by kmaeda           ###   ########.fr       */
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
		std::cout << "PLEASE, TYPE AN OPTION: ADD, SEARCH OR EXIT" << std::endl;
		std::getline (std::cin, input);
		if (input.empty() || (input != "ADD" && input != "SEARCH" && input != "EXIT" 
			&& input != "add" && input != "search" && input != "exit"))
			std::cout << "INVALID ENTRY" << std::endl;
		if (input == "EXIT" || input == "exit")
			return (0);
		else if (input == "ADD" || input == "add")
			phoneBook.addContact();
		else if (input == "SEARCH" || input == "search")
			phoneBook.searchContact();
	}
}
