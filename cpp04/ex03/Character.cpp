/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:22:51 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/02 19:35:44 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character(void) : ICharacter(), _name("")
{
	std::cout << "Character default constructor called" << std::endl;
	this->initInventory();
	return ;
}

Character::Character(std::string name) : ICharacter(), _name(name)
{
	std::cout << "Character constructor called" << std::endl;
	this->initInventory();
	return ;
}

Character::Character(const Character &obj)
{
	std::cout << "Character copy constructor called" << std::endl;
	if (this != &obj)
	{
		this->initInventory();
		*this = obj;
	}
}

Character&	Character::operator=(const Character &obj)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
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

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete (this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
	}
	return ;
}

std::string const &	Character::getName() const
{
	return (this->_name);
}

AMateria *Character::getAMateria(int idx) const
{
	if ((0 <= idx && idx <= 3) && this->_inventory[idx] != NULL)
		return this->_inventory[idx];
	return NULL;
}

void	Character::equip(AMateria* m)
{
	if (!m)
		std::cout << "Invalid materia" << std::endl;
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = m;
				return ;
			}
		}
		std::cout << "Inventory full" << std::endl;
		delete m;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Invalid index" << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << "Nothing to be unequipped" << std::endl;
	else
		this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Invalid index" << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << "Nothing to be used" << std::endl;
	else
		this->_inventory[idx]->use(target);
}

void	Character::initInventory(void)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}
