/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:36:26 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/22 20:09:19 by byoshimo         ###   ########.fr       */
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
		Weapon 		*_weaponB;
		std::string	_name;

	public:
		HumanB(std::string newName);
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon &newWeapon);
};

#endif