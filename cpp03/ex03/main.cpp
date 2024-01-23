/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:17:00 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/23 18:24:20 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	ScavTrap	c("C");
	FragTrap	d("D");
	std::cout << std::endl << "DiamondTrap constructors:" << std::endl;
	DiamondTrap	e("E");
	DiamondTrap f;

	std::cout << std::endl;
	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	e.getStatus();
	f.getStatus();

	std::cout << "-----------" << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.attack("D");
	d.takeDamage(b.getAttackDamage());
	c.attack("A");
	a.takeDamage(c.getAttackDamage());
	c.attack("D");
	d.takeDamage(c.getAttackDamage());
	d.attack("C");
	c.takeDamage(d.getAttackDamage());
	d.highFivesGuys();
	b.beRepaired(1);
	c.guardGate();
	d.attack("E");
	e.takeDamage(d.getAttackDamage());
	e.attack("D");
	d.takeDamage(e.getAttackDamage());
	f.attack("E");
	e.takeDamage(f.getAttackDamage());
	std::cout << "-----------" << std::endl << std::endl;

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	e.getStatus();
	f.getStatus();
	e.whoAmI();
	f.whoAmI();

	f = e;
	f.whoAmI();
	std::cout << std::endl;
}