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
	this->type = "";
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
		this->type = obj.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	if (this->getType() == "Cat")
		std::cout << "Meow!" << std::endl;
	else if (this->getType() == "Dog")
		std::cout << "Woof!" << std::endl;
	else
		std::cout << "Generic animal sound!" << std::endl;
}
