/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:18:19 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/13 21:27:41 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_mind = new Brain();
	return ;
}

Cat::Cat(const Cat &obj)
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
		this->_mind = new Brain(*(obj.getBrain()));
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete (this->_mind);
	return ;
}

Brain*	Cat::getBrain(void) const
{
	return (this->_mind);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
