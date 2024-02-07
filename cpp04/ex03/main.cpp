/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:55:11 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/07 18:50:36 by byoshimo         ###   ########.fr       */
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
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl << "----- DEEP COPY TEST -----" << std::endl << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		Character a("a");
		AMateria* tmp;
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
		std::cout << std::endl;
		delete src;
	}
	{
		std::cout << std::endl << "----- INVENTORY AND MATERIALS TEST -----" << std::endl << std::endl;
		IMateriaSource	*src = new MateriaSource();
		ICharacter		*character = new Character("character");

		std::cout << std::endl << "Learning materials:" << std::endl;
		for (int i = 0; i < 5; i++)
			src->learnMateria(new Cure());

		std::cout << std::endl << "Equip materials in inventory:" << std::endl;
		for (int i = 0; i < 5; i++)
			character->equip(src->createMateria("cure"));

		std::cout << std::endl << "Using materials:" << std::endl;
		character->use(0, *character);
		character->use(1, *character);
		character->use(2, *character);
		character->use(3, *character);
		character->use(4, *character);

		std::cout << std::endl << "Unequip materials:" << std::endl;
		AMateria* tmp;
		tmp = &(*dynamic_cast<Character *>(character)->getAMateria(0));
		character->unequip(0);
		delete tmp;
		tmp = &(*dynamic_cast<Character *>(character)->getAMateria(1));
		character->unequip(1);
		delete tmp;
		tmp = &(*dynamic_cast<Character *>(character)->getAMateria(2));
		character->unequip(2);
		delete tmp;
		tmp = &(*dynamic_cast<Character *>(character)->getAMateria(3));
		character->unequip(3);
		delete tmp;
		tmp = &(*dynamic_cast<Character *>(character)->getAMateria(4));
		character->unequip(4);
		delete tmp;

		std::cout << std::endl << "Using the materials again (INVENTORY EMPTY):" << std::endl;
		character->use(0, *character);
		character->use(1, *character);
		character->use(2, *character);
		character->use(3, *character);
		std::cout << std::endl;

		delete src;
		delete character;
	}
	{
		std::cout << std::endl << "----- MATERIA SOURCE TEST -----" << std::endl << std::endl;
		Character	bob("Bob");
		Character	any("Any");
		IMateriaSource	*src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());

		std::cout << std::endl << "Original:" << std::endl;
		bob.equip(src->createMateria("ice"));
		bob.equip(src->createMateria("cure"));
		bob.use(0, bob);
		bob.use(1, bob);
		bob.use(2, bob);
		bob.use(-1, bob);
		bob.use(42, bob);
		bob.use(100, bob);
		std::cout << std::endl;

		IMateriaSource	*cpySrc = new MateriaSource(*dynamic_cast<MateriaSource *>(src));
		std::cout << std::endl << "Copy:" << std::endl;
		any.equip(cpySrc->createMateria("ice"));
		any.equip(cpySrc->createMateria("cure"));
		any.use(0, any);
		any.use(1, any);
		any.use(2, any);
		any.use(-1, any);
		any.use(42, any);
		any.use(100, any);
		std::cout << std::endl;

		delete src;
		delete cpySrc;
	}
	return 0;
}