/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:36:32 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/22 20:07:24 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon *weaponA;
		std::string	name;

	public:
		HumanA(std::string newName, Weapon &newWeapon);
		~HumanA(void);

		void	attack(void);
};

#endif