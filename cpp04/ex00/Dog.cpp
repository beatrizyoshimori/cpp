/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:11:09 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/13 20:04:25 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog(const Dog &obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Dog&	Dog::operator=(const Dog &obj)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
