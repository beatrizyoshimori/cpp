/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:52:12 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/21 15:49:56 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
# define MATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(std::string const & type);
		AMateria(void);
		AMateria(const AMateria &obj);
		AMateria& operator=(const AMateria &obj);
		virtual ~AMateria(void);

		std::string const &	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif