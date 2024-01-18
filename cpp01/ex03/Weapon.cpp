/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:39:34 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/21 22:21:09 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

Weapon::~Weapon(void)
{
	return ;
}

std::string	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}
