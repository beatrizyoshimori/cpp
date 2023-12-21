/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:22:54 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/21 16:18:45 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria	*_inventory[4];
		std::string	_name;

	public:
		Character(std::string name);
		Character(void);
		Character(const Character &obj);
		Character& operator=(const Character &obj);
		virtual ~Character(void);

		std::string const &	getName() const;
		AMateria *getAMateria(int idx) const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif