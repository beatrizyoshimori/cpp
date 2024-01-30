/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:18:19 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/30 20:08:57 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	return ;
}

Cat::Cat(const Cat &obj) : _brain(new Brain(*obj.getBrain()))
{
	std::cout << "Cat copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Cat&	Cat::operator=(const Cat &obj)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_type = obj.getType();
		*this->_brain = *obj.getBrain();
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete (this->_brain);
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
}

std::string	Cat::getBrainIdea(int index) const
{
	if (index < 0 || index >= 100)
		return (NULL);
	return (this->getBrain()->getIdea(index));
}

void	Cat::setBrainIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Index is out of range" << std::endl;
		return ;
	}
	this->getBrain()->setIdea(index, idea);
}
