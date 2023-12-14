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
	this->type = "";
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
		this->type = obj.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
	return ;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	if (this->getType() == "Cat")
		std::cout << "Wrong Meow!" << std::endl;
	else if (this->getType() == "Dog")
		std::cout << "Wrong Woof!" << std::endl;
	else
		std::cout << "Generic wrong animal sound!" << std::endl;
}
