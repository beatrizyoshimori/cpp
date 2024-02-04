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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	a("A", 150);
	Bureaucrat	b("B", 1);
	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm	robotomy("Rob");
	PresidentialPardonForm presidential("Bob");

	std::cout << std::endl << a << std::endl << b << std::endl << std::endl;

	std::cout << "---------- SHRUBBERY FORM TEST ----------" << std::endl << std::endl;
	std::cout << "A tries to sign shrubbery:" << std::endl;
	try
	{
		a.signForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "A tries to execute shrubbery:" << std::endl;
	try
	{
		a.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "B tries to execute shrubbery:" << std::endl;
	try
	{
		b.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "B tries to sign shrubbery:" << std::endl;
	try
	{
		b.signForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "B tries to execute shrubbery:" << std::endl;
	try
	{
		b.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "---------- ROBOTOMY FORM TEST ----------" << std::endl << std::endl;
	std::cout << "A tries to sign robotomy:" << std::endl;
	try
	{
		a.signForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "A tries to execute robotomy:" << std::endl;
	try
	{
		a.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "B tries to execute robotomy:" << std::endl;
	try
	{
		b.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "B tries to sign robotomy:" << std::endl;
	try
	{
		b.signForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "B tries to execute robotomy:" << std::endl;
	try
	{
		b.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "---------- PRESIDENTIAL FORM TEST ----------" << std::endl << std::endl;
	std::cout << "A tries to sign presidential:" << std::endl;
	try
	{
		a.signForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "A tries to execute presidential:" << std::endl;
	try
	{
		a.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "B tries to execute presidential:" << std::endl;
	try
	{
		b.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "B tries to sign presidential:" << std::endl;
	try
	{
		b.signForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "B tries to execute presidential:" << std::endl;
	try
	{
		b.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
