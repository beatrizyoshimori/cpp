/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:21:20 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/11 17:20:33 by byoshimo         ###   ########.fr       */
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
		std::cout << "First name: ";
		getline(std::cin, name);
		if (!name.empty())
			break ;
		std::cout << RED << "Invalid first name." << std::endl << RESET;
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
		std::cout << RED << "Invalid last name." << std::endl << RESET;
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
		std::cout << RED << "Invalid nickname." << std::endl << RESET;
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
		if (!phoneNumber.empty() && phoneNumber.find_first_not_of("0123456789()-") == std::string::npos)
			break ;
		std::cout << RED << "Invalid phone number." << std::endl << RESET;
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
		std::cout << RED << "Invalid darkest secret." << std::endl << RESET;
	}
	this->_darkestSecret = darkestSecret;
}

std::string	Contact::truncateInfo(std::string info)
{
	std::string str;

	str = info;
	if (str.length() > 10)
	{
		str.erase(9, std::string::npos);
		str.push_back('.');
	}
	return (str);
}

void	Contact::printPhonebookContact(void)
{
	std::cout << std::right << "|" << 
	std::setw(10) << truncateInfo(this->_firstName) << "|" <<
	std::setw(10) << truncateInfo(this->_lastName) << "|" <<
	std::setw(10) << truncateInfo(this->_nickname) << "|" << std::endl;
}

void	Contact::printContactInfo(void)
{
	std::cout << CLEAR_WINDOW << std::setw(17) << std::left << "First name: " << this->_firstName << std::endl;
	std::cout << std::setw(17) << std::left << "Last name: " << this->_lastName << std::endl;
	std::cout << std::setw(17) << std::left << "Nickname: " << this->_nickname << std::endl;
	std::cout << std::setw(17) << std::left << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << std::setw(17) << std::left << "Darkest secret: " << this->_darkestSecret << std::endl;
}
