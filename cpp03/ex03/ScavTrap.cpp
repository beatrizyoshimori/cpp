/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:17:05 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 22:00:17 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	ClapTrap::hitPoints = 100;
	ClapTrap::energyPoints = 50;
	ClapTrap::attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj.getName())
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.getName();
		this->hitPoints = obj.getHitPoints();
		this->energyPoints = obj.getEnergyPoints();
		this->attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints < 1 || this->energyPoints < 1)
		return ;
	this->energyPoints--;
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints < 1)
	{
		std::cout << "ScavTrap " << this->getName() << " took 0 points of damage" << std::endl;
		return ;
	}
	else if (this->hitPoints < amount)
	{
		std::cout << "ScavTrap " << this->getName() << " took " << this->hitPoints << " points of damage" << std::endl;
		this->hitPoints = 0;
		return ;
	}
	this->hitPoints -= amount;
	std::cout << "ScavTrap " << this->getName() << " took " << amount << " points of damage" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode" << std::endl;
}
