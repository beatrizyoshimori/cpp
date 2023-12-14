/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:02:34 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/13 21:54:41 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(const Animal &obj);
		Animal& operator=(const Animal &obj);
		virtual ~Animal(void);

		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif