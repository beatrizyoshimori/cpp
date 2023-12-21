/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:33:01 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/21 16:06:53 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &obj);
		Ice& operator=(const Ice &obj);
		~Ice(void);

		Ice*	clone() const;
		void	use(ICharacter& target);
};

#endif