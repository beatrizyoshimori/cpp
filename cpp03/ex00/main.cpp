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

	a.getStatus();
	b.getStatus();
	
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(1);

	a.getStatus();
	b.getStatus();
}