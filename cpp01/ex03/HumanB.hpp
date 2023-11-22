/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:36:26 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/21 22:23:23 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *weaponB;
		std::string	name;

	public:
		HumanB(void);
		~HumanB(void);
		HumanB(std::string newName);


		void	attack(void);
		void	setWeapon(Weapon newWeapon);
};

#endif