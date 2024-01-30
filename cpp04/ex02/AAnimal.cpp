/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:02:24 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/30 20:11:02 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal default constructor called" << std::endl;
	this->_type = "";
	return ;
}

AAnimal::AAnimal(const AAnimal &obj)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

AAnimal&	AAnimal::operator=(const AAnimal &obj)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
	return ;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Generic animal sound!" << std::endl;
}
