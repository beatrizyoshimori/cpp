/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:18:19 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/13 20:04:32 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
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
		this->_type = obj.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
