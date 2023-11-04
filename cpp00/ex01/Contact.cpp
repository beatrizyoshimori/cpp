/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:21:20 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/03 20:46:25 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::setFirstName(void)
{
	std::string	name;

	while (true)
	{
		std::cout << CLEAR_WINDOW << "First name: ";
		getline(std::cin, name);
		if (!name.empty())
			break ;
	}
	this->_firstName = name;
}

void	Contact::setLastName(void)
{
	std::string	lastName;

	while (true)
	{
		std::cout << "Last name: ";
		getline(std::cin, lastName);
		if (!lastName.empty())
			break ;
	}
	this->_lastName = lastName;
}

void	Contact::setNickname(void)
{
	std::string	nickname;

	while (true)
	{
		std::cout << "Nickname: ";
		getline(std::cin, nickname);
		if (!nickname.empty())
			break ;
	}
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(void)
{
	std::string	phoneNumber;

	while (true)
	{
		std::cout << "Phone number: ";
		getline(std::cin, phoneNumber);
		if (!phoneNumber.empty())
			break ;
	}
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(void)
{
	std::string	darkestSecret;

	while (true)
	{
		std::cout << "Darkest secret: ";
		getline(std::cin, darkestSecret);
		if (!darkestSecret.empty())
			break ;
	}
	this->_darkestSecret = darkestSecret;
}

void	Contact::printPhonebookContact(void)
{
	std::cout << std::right << "|" << 
	std::setw(10) << this->_firstName << "|" <<
	std::setw(10) << this->_lastName << "|" <<
	std::setw(10) << this->_nickname << "|" << std::endl;
}

void	Contact::printContactInfo(void)
{
	std::cout << CLEAR_WINDOW << std::setw(17) << std::left << "First name: " << this->_firstName << std::endl;
	std::cout << std::setw(17) << std::left << "Last name: " << this->_lastName << std::endl;
	std::cout << std::setw(17) << std::left << "Nickname: " << this->_nickname << std::endl;
	std::cout << std::setw(17) << std::left << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << std::setw(17) << std::left << "Darkest secret: " << this->_darkestSecret << std::endl;
}
