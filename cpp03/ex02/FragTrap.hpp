/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:53:06 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/04 19:53:08 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &obj);
		FragTrap& operator=(const FragTrap &obj);
		~FragTrap(void);

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif