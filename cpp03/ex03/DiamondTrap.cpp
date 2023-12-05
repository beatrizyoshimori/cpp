/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:12:40 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 22:09:16 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->name = name;
	// this->hitPoints = FragTrap::hitPoints;
	// this->energyPoints = ScavTrap::energyPoints;
	// this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj.getName()), ScavTrap(obj.getName()), FragTrap(obj.getName())
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.getName();
		this->hitPoints = obj.getHitPoints();
		this->energyPoints = obj.getEnergyPoints();
		this->attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return ;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints < 1)
	{
		std::cout << "DiamondTrap " << this->getName() << " took 0 points of damage" << std::endl;
		return ;
	}
	else if (this->hitPoints < amount)
	{
		std::cout << "DiamondTrap " << this->getName() << " took " << this->hitPoints << " points of damage" << std::endl;
		this->hitPoints = 0;
		return ;
	}
	this->hitPoints -= amount;
	std::cout << "DiamondTrap " << this->getName() << " took " << amount << " points of damage" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << this->getName() << std::endl;
}