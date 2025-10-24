/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:22:58 by kmaeda            #+#    #+#             */
/*   Updated: 2025/10/23 17:23:01 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

char	ft_add()
{

}

int	main()
{
	std::string	input;

	while (1)
	{
		std::cout << "PLEASE, TYPE AN OPTION: ADD, SEARCH OR EXIT" << std::endl;
		std::getline (std::cin, input);
		if (input.empty() || (input != "ADD" && input != "SEARCH" && input != "EXIT"))
			std::cout << "INVALID ENTRY" << std::endl;
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
		/*else if (input == "SEARCH")*/
	}
}
