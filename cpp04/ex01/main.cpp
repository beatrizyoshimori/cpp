/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:02:02 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/07 18:34:25 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	std::cout << "---------" << std::endl;
	
	const Animal* meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}
	for (int i = 0; i < 10; i ++)
	{
		std::cout << meta[i] << std::endl;
		meta[i]->makeSound();
	}
	for (int i = 0; i < 10; i ++)
		delete (meta[i]);
	std::cout << "---------" << std::endl;

	Cat	cat;
	for (int i = 0; i < 100; i++)
		cat.setBrainIdea(i, "I want Whiskas!");
	std::cout << "Cat ideias:" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << cat.getBrainIdea(i) << std::endl;
	std::cout << "---------" << std::endl;

	Cat	Tom;
	Tom = cat;
	std::cout << Tom.getType() << std::endl;
	for (int i = 0; i < 100; i++)
		Tom.setBrainIdea(i, "I don't want Whiskas anymore!");
	std::cout << "Tom ideas:" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << Tom.getBrainIdea(i) << std::endl;
	std::cout << "---------" << std::endl;

	std::cout << "Cat ideias:" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << cat.getBrainIdea(i) << std::endl;
	std::cout << "---------" << std::endl;

	Cat	MandaChuva(Tom);
	std::cout << "MandaChuva ideas:" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << MandaChuva.getBrainIdea(i) << std::endl;
	return (0);
}
