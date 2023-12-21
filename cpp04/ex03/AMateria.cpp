/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:54:42 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/21 16:08:30 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor called" << std::endl;
	this->type = "";
	return ;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria constructor called" << std::endl;
	this->type = type;
	return ;
}

AMateria::AMateria(const AMateria &obj)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

AMateria&	AMateria::operator=(const AMateria &obj)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &obj)
		this->type = obj.getType();
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
	return ;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	return ;
}
