/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:55:11 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/31 21:50:43 by byoshimo         ###   ########.fr       */
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

	std::cout << "-----------" << std::endl << std::endl;
	// MateriaSource s;
	// s.learnMateria(new Ice());
	// s.learnMateria(new Cure());
	// std::cout << s.getAMateria(0)->getType() << std::endl << s.getAMateria(1)->getType() << std::endl;
	Character a("a");
	tmp = src->createMateria("ice");
	a.equip(tmp);
	Character b = a;
	std::cout << "1" << a.getAMateria(0)->getType() << std::endl;
	std::cout << "2" << b.getAMateria(0)->getType() << std::endl;
	// a.unequip(0);
	tmp = a.getAMateria(0);
	a.unequip(0);
	delete tmp;
	tmp = src->createMateria("cure");
	a.equip(tmp);
	std::cout << "3" << a.getAMateria(0)->getType() << std::endl;
	std::cout << "4" << b.getAMateria(0)->getType() << std::endl;
	// std::cout << "4" << b.getAMateria(1)->getType() << std::endl;
	// std::cout << a.getAMateria(0)->getType() << std::endl;
	// Character b;
	// b = a;
	// std::cout << b.getAMateria(0)->getType() << std::endl;
	// std::cout << "-----------" << std::endl << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}