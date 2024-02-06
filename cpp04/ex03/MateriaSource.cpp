/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:10:27 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/31 19:25:15 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &obj)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete (this->_inventory[i]);
				this->_inventory[i] = NULL;
			}
			if (obj.getAMateria(i))
				this->_inventory[i] = obj.getAMateria(i)->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->getAMateria(i))
			delete (this->_inventory[i]);
		this->_inventory[i] = NULL;
	}
	return ;
}

AMateria *MateriaSource::getAMateria(int idx) const
{
	if ((0 <= idx && idx <= 3) && this->_inventory[idx] != NULL)
		return this->_inventory[idx];
	return NULL;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Maximum number of materials learned" << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i]->getType() == type)
			return (this->getAMateria(i)->clone());
	}
	return (NULL);
}
