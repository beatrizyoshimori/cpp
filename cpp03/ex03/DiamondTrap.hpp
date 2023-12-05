/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:12:55 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 22:04:18 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name;
		using	FragTrap::hitPoints;
		using	ScavTrap::energyPoints;
		using	FragTrap::attackDamage;

	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &obj);
		DiamondTrap& operator=(const DiamondTrap &obj);
		~DiamondTrap(void);

		void	takeDamage(unsigned int amount);
		void	whoAmI();
		using	ScavTrap::attack;
};

#endif