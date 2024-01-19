/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:51:10 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 22:01:06 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	ScavTrap	c("C");
	ScavTrap	d;

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(1);
	c.attack("A");
	a.takeDamage(c.getAttackDamage());
	c.guardGate();
	b.attack("C");
	c.takeDamage(b.getAttackDamage());
	c.beRepaired(10);
	d.guardGate();

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
}