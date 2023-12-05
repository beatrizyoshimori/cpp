/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:17:00 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 21:36:07 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	// ClapTrap	a("A");
	// ClapTrap	b("B");
	// ScavTrap	c("C");
	FragTrap	d("D");
	DiamondTrap	e("E");

	// a.getStatus();
	// b.getStatus();
	// c.getStatus();
	d.getStatus();
	e.getStatus();
	
	// a.attack("B");
	// b.takeDamage(a.getAttackDamage());
	// b.attack("D");
	// d.takeDamage(b.getAttackDamage());
	// c.attack("A");
	// a.takeDamage(c.getAttackDamage());
	// c.attack("D");
	// d.takeDamage(c.getAttackDamage());
	// d.attack("C");
	// c.takeDamage(d.getAttackDamage());
	// d.highFivesGuys();
	// b.beRepaired(1);
	// c.guardGate();
	d.attack("E");
	e.takeDamage(d.getAttackDamage());
	e.attack("D");
	d.takeDamage(e.getAttackDamage());

	// a.getStatus();
	// b.getStatus();
	// c.getStatus();
	d.getStatus();
	e.getStatus();
	e.whoAmI();
}