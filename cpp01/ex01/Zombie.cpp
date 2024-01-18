/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:22:24 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/13 21:54:15 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::Zombie(std::string zombieName)
{
	this->_name = zombieName;
	std::cout << this->_name << " created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string zombieName)
{
	this->_name = zombieName;
}