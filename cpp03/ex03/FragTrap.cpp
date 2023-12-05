/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:16:53 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 21:45:40 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	ClapTrap::hitPoints = 100;
	ClapTrap::energyPoints = 100;
	ClapTrap::attackDamage = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj.getName())
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

FragTrap&	FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.getName();
		this->hitPoints = obj.getHitPoints();
		this->energyPoints = obj.getEnergyPoints();
		this->attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->hitPoints < 1 || this->energyPoints < 1)
		return ;
	this->energyPoints--;
	std::cout << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " requested " << " a high five!" << std::endl;
}
