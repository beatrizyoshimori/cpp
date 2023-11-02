/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:18 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/01 22:03:46 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	PhoneBook::addContact(void)
{
	int	index;

	index = this->_index;
	if (this->_index > 7)
		this->_index = 0;
	this->_contacts[index].setFirstName();
	this->_contacts[index].setLastName();
	this->_contacts[index].setNickname();
}
