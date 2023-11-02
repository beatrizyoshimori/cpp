/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:21:20 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/01 22:06:00 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
	}
	this->_firstName = name;
	std::cout << "Added first name" << std::endl;
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
	this->_firstName = lastName;
	std::cout << "Added last name" << std::endl;
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
	this->_firstName = nickname;
	std::cout << "Added nickname" << std::endl;
}