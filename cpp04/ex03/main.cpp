/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:55:11 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/02 19:41:04 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int main()
{
	std::cout << std::endl << "----- SUBJECT TEST -----" << std::endl << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl << "----- DEEP COPY TEST -----" << std::endl << std::endl;
	Character a("a");
	tmp = src->createMateria("ice");
	a.equip(tmp);
	Character b = a;
	Character c;
	c = a;
	std::cout << std::endl << "a adress: " << &a << std::endl;
	std::cout << "b adress: " << &b << std::endl;
	std::cout << "c adress: " << &c << std::endl;
	std::cout << std::endl << "a type: " << a.getAMateria(0)->getType() << std::endl;
	std::cout << "b type: " << b.getAMateria(0)->getType() << std::endl;
	std::cout << "c type: " << c.getAMateria(0)->getType() << std::endl << std::endl;
	tmp = a.getAMateria(0);
	a.unequip(0);
	delete tmp;
	tmp = src->createMateria("cure");
	a.equip(tmp);
	std::cout << std::endl << "a type after: " << a.getAMateria(0)->getType() << std::endl;
	std::cout << "b type after: " << b.getAMateria(0)->getType() << std::endl;
	std::cout << "c type after: " << c.getAMateria(0)->getType() << std::endl;
	if (b.getAMateria(1))
		std::cout << "4" << b.getAMateria(1)->getType() << std::endl;

	std::cout << "-----------" << std::endl << std::endl;

	delete bob;
	delete me;
	delete src;
	return 0;
}