/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:53:10 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 19:59:42 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	ScavTrap	c("C");
	FragTrap	d("D");
	FragTrap	e;

	std::cout << std::endl;
	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	e.getStatus();

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
	d.beRepaired(5);
	e.highFivesGuys();
	std::cout << "-----------" << std::endl << std::endl;

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	e.getStatus();
}
