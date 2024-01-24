/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:02:24 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/13 19:41:36 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
	this->_type = "";
	return ;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Animal&	Animal::operator=(const Animal &obj)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Generic animal sound!" << std::endl;
}
