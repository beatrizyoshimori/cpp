/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:53:01 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/23 18:04:06 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << YELLOW << "FragTrap default constructor called" << RESET << std::endl;
	this->_name = "Default";
	this->_type = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << YELLOW << "FragTrap constructor called" << RESET << std::endl;
	this->_type = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj.getName())
{
	std::cout << YELLOW << "FragTrap copy constructor called" << RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

FragTrap&	FragTrap::operator=(const FragTrap &obj)
{
	std::cout << YELLOW << "FragTrap copy assignment operator called" << RESET << std::endl;
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

FragTrap::~FragTrap(void)
{
	std::cout << YELLOW << "FragTrap destructor called" << RESET << std::endl;
	return ;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints < 1 || this->_energyPoints < 1)
		return ;
	this->_energyPoints--;
	std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " requested " << " a high five!" << std::endl;
}
