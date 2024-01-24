/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:52:39 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/13 19:53:49 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Wrong Animal default constructor called" << std::endl;
	this->_type = "";
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "Wrong Animal copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
	return ;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Generic wrong animal sound!" << std::endl;
}
