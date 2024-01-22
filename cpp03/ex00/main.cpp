/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:48:27 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 19:48:30 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");

	std::cout << std::endl;
	a.getStatus();
	b.getStatus();

	std::cout << "-----------" << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(1);
	b.attack("A");
	a.takeDamage(b.getAttackDamage());
	std::cout << "-----------" << std::endl << std::endl;

	a.getStatus();
	b.getStatus();
}
