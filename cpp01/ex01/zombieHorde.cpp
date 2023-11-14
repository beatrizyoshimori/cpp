/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:22:42 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/13 21:37:08 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*Horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		Horde[i].setName(name);
	}
	return (Horde);
}
