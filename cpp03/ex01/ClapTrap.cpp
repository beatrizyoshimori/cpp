/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:49:45 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 19:49:50 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
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
		this->name = obj.getName();
		this->hitPoints = obj.getHitPoints();
		this->energyPoints = obj.getEnergyPoints();
		this->attackDamage = obj.getAttackDamage();
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
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints < 1 || this->energyPoints < 1)
		return ;
	this->energyPoints--;
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->getName() << " took 0 points of damage" << std::endl;
		return ;
	}
	else if (this->hitPoints < amount)
	{
		std::cout << "ClapTrap " << this->getName() << " took " << this->hitPoints << " points of damage" << std::endl;
		this->hitPoints = 0;
		return ;
	}
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->getName() << " took " << amount << " points of damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints < 1 || this->energyPoints < 1)
		return ;
	this->hitPoints += amount;
	this->energyPoints--;
	std::cout << "ClapTrap " << this->getName() << " was repaired, getting " << amount << " hit points back" << std::endl;
}

void	ClapTrap::getStatus(void)
{
	std::cout << this->getName() << " status:" << std::endl
		<< "Hit points: " << this->getHitPoints() << std::endl
		<< "Energy points: " << this->getEnergyPoints() << std::endl
		<< "Attack damage: " << this->getAttackDamage() << std::endl << std::endl;
}
