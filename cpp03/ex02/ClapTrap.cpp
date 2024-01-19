/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:48:19 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/06 22:03:34 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "Default";
	this->_type = "ClapTrap";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_name = name;
	this->_type = "ClapTrap";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_name = obj.getName();
		this->_type = obj.getType();
		this->_hitPoints = obj.getHitPoints();
		this->_energyPoints = obj.getEnergyPoints();
		this->_attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

std::string	ClapTrap::getType(void) const
{
	return (this->_type);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints < 1 || this->_energyPoints < 1)
		return ;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1)
	{
		std::cout << this->getType() << " " << this->getName() << " is dead and took 0 points of damage" << std::endl;
		return ;
	}
	else if (this->_hitPoints < amount)
	{
		std::cout << this->getType() << " " << this->getName() << " took " << this->_hitPoints << " points of damage and died" << std::endl;
		this->_hitPoints = 0;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << this->getType() << " " << this->getName() << " took " << amount << " points of damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints < 1 || this->_energyPoints < 1)
		return ;
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << this->getType() << " " << this->getName() << " was repaired, getting " << amount << " hit points back" << std::endl;
}

void	ClapTrap::getStatus(void)
{
	std::cout << this->getName() << " status:" << std::endl
		<< "Hit points: " << this->getHitPoints() << std::endl
		<< "Energy points: " << this->getEnergyPoints() << std::endl
		<< "Attack damage: " << this->getAttackDamage() << std::endl << std::endl;
}
