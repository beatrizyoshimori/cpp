/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:20:01 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/04 14:46:15 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout << std::endl << MAGENTA << "Type a command:" << std::endl;
		std::cout << std::setw(8) << std::left << "ADD: " << "saves a new contact" << std::endl;
		std::cout << std::setw(8) << std::left << "SEARCH: " << "displays a specific contact" << std::endl;
		std::cout << std::setw(8) << std::left << "EXIT: " << "quits the program" << std::endl << std::endl << RESET;
		std::cout << "> ";
		getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << CLEAR_WINDOW << RED << "Wrong input!" << RESET << std::endl;
	}
	return (0);
}