/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:40:11 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/13 21:53:07 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	public:
		Zombie(std::string zombieName);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);

	private:
		std::string	name;

};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif