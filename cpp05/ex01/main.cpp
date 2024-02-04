/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:38:45 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/17 21:21:19 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Form		f("Contract", 0, 150);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form		f("Contract", 151, 150);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form		f("Contract", 50, 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form		f("Contract", 50, 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat	a("A", 100);
	Bureaucrat	b("B", 50);
	Form		f("Contract", 50, 50);

	std::cout << std::endl << a << std::endl << b << std::endl;
	std::cout << f << std::endl << std::endl;
	std::cout << "A tries to sign contract:" << std::endl;
	try
	{
		a.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << f << std::endl;
	std::cout << std::endl << "B tries to sign contract:" << std::endl;
	try
	{
		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << f << std::endl;
	std::cout << std::endl << "B tries to sign contract:" << std::endl;
	try
	{
		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << a << std::endl << b << std::endl;
	std::cout << f << std::endl << std::endl;
	return (0);
}
