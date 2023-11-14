/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:21:55 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/13 21:33:22 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <vector>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string zombieName);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string zombieName);

	private:
		std::string	name;

};

Zombie*	zombieHorde( int N, std::string name );

#endif