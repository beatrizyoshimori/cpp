/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:20:01 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/01 21:56:14 by byoshimo         ###   ########.fr       */
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
		std::cout << "> ";
		getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			std::cout << "search" << std::endl;
		else if (input == "EXIT") break ;
		else
		{
			std::cout << "Usage:" << std::endl;
			std::cout << "ADD: save a new contact" << std::endl;
			std::cout << "SEARCH: display a specific contact" << std::endl;
			std::cout << "EXIT: quit the program" << std::endl;
		}
	}
	Contact c;
	return (0);
}