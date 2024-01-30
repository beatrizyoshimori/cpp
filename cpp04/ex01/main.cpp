/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:02:02 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/21 11:41:57 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;
	// delete i;

	// const Animal* meta[10];
	// for (int i = 0; i < 10; i++)
	// {
	// 	if (i < 5)
	// 		meta[i] = new Dog();
	// 	else
	// 		meta[i] = new Cat();
	// }
	// for (int i = 0; i < 10; i ++)
	// {
	// 	std::cout << meta[i] << std::endl;
	// 	meta[i]->makeSound();
	// }
	// for (int i = 0; i < 10; i ++)
	// 	delete (meta[i]);

	// std::cout << "---------" << std::endl;
	// Cat Tom;
	// Cat Bi;
	// std::cout << Tom.getBrain()->getIdea(0) << std::endl;
	// Tom = Bi;
	// std::cout << "---------" << std::endl;
	// return (0);


	Cat	cat;

	for (int i = 0; i < 100; i++)
		cat.getBrain()->setIdea(i, "I want Whiskas!");
	// for (int i = 0; i < 100; i++)
	// 	std::cout << cat.getBrainIdea(i) << std::endl;

	Cat	Tom = cat;
	std::cout << Tom.getType() << std::endl;
	for (int i = 0; i < 100; i++)
		Tom.getBrain()->setIdea(i, "I don't want Whiskas anymore!");
	for (int i = 0; i < 100; i++)
		std::cout << Tom.getBrain()->getIdea(i) << std::endl;

	// Cat	MandaChuva(Tom);
	// for (int i = 0; i < 100; i++)
	// 	std::cout << MandaChuva.getBrainIdea(i) << std::endl;
	return (0);
}
