/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseFunctions.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:11:11 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/26 18:11:12 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void)
{
	srand(time(NULL));
	char	type = 'A' + rand() % 3;

	std::cout << "Generated " << type << " type class." << std::endl;
	switch (type)
	{
		case 'A':
			return new A();
		case 'B':
			return new B();
		case 'C':
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	std::cout << "Object type: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "[none]" << std::endl;
}

void	identify(Base& p)
{
	std::cout << "Object type: ";
	try
	{
		A	a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (...)
	{
		try
		{
			B	b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (...)
		{
			try
			{
				C	c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (...)
			{
				std::cout << "[none]" << std::endl;
			}
		}
	}
}
