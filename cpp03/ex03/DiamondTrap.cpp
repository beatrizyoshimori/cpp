/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:12:40 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/23 18:14:02 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << MAGENTA << "DiamondTrap default constructor called" << RESET << std::endl;
	ClapTrap::_name = "Default_clap_name";
	this->_name = "Default";
	this->_type = "DiamondTrap";
	this->_hitPoints = FragTrap::HIT_POINTS;
	this->_energyPoints = ScavTrap::ENERGY_POINTS;
	this->_attackDamage = FragTrap::ATTACK_DAMAGE;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	std::cout << MAGENTA << "DiamondTrap constructor called" << RESET << std::endl;
	this->_name = name;
	this->_type = "DiamondTrap";
	this->_hitPoints = FragTrap::HIT_POINTS;
	this->_energyPoints = ScavTrap::ENERGY_POINTS;
	this->_attackDamage = FragTrap::ATTACK_DAMAGE;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj.getName()), ScavTrap(obj.getName()), FragTrap(obj.getName())
{
	std::cout << MAGENTA << "DiamondTrap copy constructor called" << RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << MAGENTA << "DiamondTrap copy assignment operator called" << RESET << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		ClapTrap::_name = obj.getName();
		this->_type = obj.getType();
		this->_hitPoints = obj.getHitPoints();
		this->_energyPoints = obj.getEnergyPoints();
		this->_attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << MAGENTA << "DiamondTrap destructor called" << RESET << std::endl;
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->getName() << std::endl;
}
