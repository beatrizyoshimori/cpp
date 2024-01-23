/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:51:14 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/23 18:03:09 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << GREEN << "ScavTrap default constructor called" << RESET << std::endl;
	this->_name = "Default";
	this->_type = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN << "ScavTrap constructor called" << RESET << std::endl;
	this->_type = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj.getName())
{
	std::cout << GREEN << "ScavTrap copy constructor called" << RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << GREEN << "ScavTrap copy assignment operator called" << RESET << std::endl;
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

ScavTrap::~ScavTrap(void)
{
	std::cout << GREEN << "ScavTrap destructor called" << RESET << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints < 1 || this->_energyPoints < 1)
		return ;
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode" << std::endl;
}
