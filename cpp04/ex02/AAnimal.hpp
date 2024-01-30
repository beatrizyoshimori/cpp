/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:02:34 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/30 20:10:46 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class	AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal(void);
		AAnimal(const AAnimal &obj);
		AAnimal& operator=(const AAnimal &obj);
		virtual ~AAnimal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif