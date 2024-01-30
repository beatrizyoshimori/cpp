/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:11:09 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/30 19:51:31 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	return ;
}

Dog::Dog(const Dog &obj) : _brain(new Brain(*obj.getBrain()))
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
	delete (this->_brain);
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}

std::string	Dog::getBrainIdea(int index) const
{
	if (index < 0 || index >= 100)
		return (NULL);
	return (this->getBrain()->getIdea(index));
}

void	Dog::setBrainIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Index is out of range" << std::endl;
		return ;
	}
	this->getBrain()->setIdea(index, idea);
}
