/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:16:57 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/05 22:12:28 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	protected:
		std::string		type;
		const static int HIT_POINTS = 100;
		const static int ENERGY_POINTS = 100;
		const static int ATTACK_DAMAGE = 30;

	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &obj);
		FragTrap& operator=(const FragTrap &obj);
		~FragTrap(void);

		void	attack(const std::string& target);
		// void	takeDamage(unsigned int amount);
		void	highFivesGuys(void);
};

#endif