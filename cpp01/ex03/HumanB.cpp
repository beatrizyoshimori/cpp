/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:46:54 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/20 17:19:05 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
	this->_name = newName;
	this->_weaponB = NULL;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::attack(void)
{
	if (this->_weaponB == NULL)
	{
		std::cout << this->_name << " attacks without a weapon" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weaponB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->_weaponB = &newWeapon;
}
