/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:16:37 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/30 20:08:38 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(const Cat &obj);
		Cat& operator=(const Cat &obj);
		~Cat(void);

		void		makeSound(void) const;
		Brain*		getBrain(void) const;
		std::string	getBrainIdea(int index) const;
		void		setBrainIdea(int index, std::string idea);
};

#endif