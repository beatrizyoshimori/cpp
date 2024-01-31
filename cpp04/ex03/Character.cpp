/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:22:51 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/30 21:45:16 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : ICharacter(), _name("")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(std::string name) : ICharacter(), _name(name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(const Character &obj)
{
	std::cout << "Character copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
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
		delete (this->_inventory[i]);
		this->_inventory[i] = NULL;
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
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}
void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <=3 && this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <=3 && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}

void	Character::initInventory(void)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}
