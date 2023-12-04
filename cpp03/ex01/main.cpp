/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:51:10 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 19:51:12 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	ScavTrap	c("C");

	a.getStatus();
	b.getStatus();
	c.getStatus();
	
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(1);
	c.attack("A");
	a.takeDamage(c.getAttackDamage());
	c.guardGate();

	a.getStatus();
	b.getStatus();
	c.getStatus();
}