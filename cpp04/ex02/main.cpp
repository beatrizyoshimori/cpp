/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:02:02 by byoshimo          #+#    #+#             */
/*   Updated: 2023/12/21 11:41:52 by byoshimo         ###   ########.fr       */
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
	return (0);
}
