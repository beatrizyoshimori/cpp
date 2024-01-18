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
	Bureaucrat	a("A", 100);
	Form		f("Contract", 50, 50);

	std::cout << std::endl << a << std::endl;
	std::cout << f << std::endl;
	try
	{
		a.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << a << std::endl;
	std::cout << f << std::endl;
	try
	{
		a.incrementGrade(50);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << a << std::endl;
	std::cout << f << std::endl;
	try
	{
		a.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << a << std::endl;
	std::cout << f << std::endl;
	try
	{
		a.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << a << std::endl;
	std::cout << f << std::endl;
	return (0);
}
