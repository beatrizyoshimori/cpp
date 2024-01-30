/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:09:04 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/30 20:08:49 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Dog(void);
		Dog(const Dog &obj);
		Dog& operator=(const Dog &obj);
		~Dog(void);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
		std::string	getBrainIdea(int index) const;
		void		setBrainIdea(int index, std::string idea);
};

#endif