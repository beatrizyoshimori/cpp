/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:54:35 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/13 19:55:24 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "Wrong Cat default constructor called" << std::endl;
	this->_type = "Cat";
	return ;
}

WrongCat::WrongCat(const WrongCat &obj)
{
	std::cout << "Wrong Cat copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongCat&	WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "Wrong Cat copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong meow!" << std::endl;
}
