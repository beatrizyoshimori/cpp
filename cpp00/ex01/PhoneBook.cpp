/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:18 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/03 21:09:46 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called" << std::endl;
	this->_index = 0;
	this->numberOfContacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	PhoneBook::addContact(void)
{
	if (this->_index > 7)
	{
		this->_index = 0;
		this->numberOfContacts = 7;
	}
	this->_contacts[this->_index].setFirstName();
	this->_contacts[this->_index].setLastName();
	this->_contacts[this->_index].setNickname();
	this->_contacts[this->_index].setPhoneNumber();
	this->_contacts[this->_index].setDarkestSecret();
	std::cout << GREEN << std::endl << "Added new contact!" << std::endl << RESET;
	if (this->numberOfContacts < 7)
		this->numberOfContacts = this->_index;
	this->_index++;
}

void	PhoneBook::searchContact(void)
{
	std::cout << CLEAR_WINDOW << std::endl;
	std::cout << BLUE << std::setw(27) << std::right << "PHONEBOOK" << RESET << std::endl;
	std::cout << std::right << "|" << 
	std::setw(10) << "Index" << "|" <<
	std::setw(10) << "First name" << "|" <<
	std::setw(10) << "Last name" << "|" <<
	std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i <= this->numberOfContacts; i++)
	{
		std::cout << std::right << "|" << 
		std::setw(10) << i + 1;
		this->_contacts[i].printPhonebookContact();
	}
	std::string	input;
	int	contactIndex;
	while (true)
	{
		std::cout << std::endl << "Choose an index: ";
		getline(std::cin, input);
		contactIndex = std::atoi(input.c_str());
		if (input.length() != 1  || contactIndex < 1 || contactIndex > 8 || contactIndex > this->numberOfContacts + 1)
			std::cout << RED << "Invalid index" << RESET << std::endl;
		else
			break ;
	}
	this->_contacts[contactIndex - 1].printContactInfo();
}
