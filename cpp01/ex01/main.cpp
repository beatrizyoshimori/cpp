/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:34:27 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/13 21:35:16 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *Horde = zombieHorde(5, "oi");
	for (int i = 0; i < 5; i++)
		Horde[i].announce();
	delete[] Horde;
	return (0);
}