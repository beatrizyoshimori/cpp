/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:39:34 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/20 16:24:47 by byoshimo         ###   ########.fr       */
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

const std::string	Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}
