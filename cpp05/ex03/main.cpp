/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:38:45 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/16 21:55:05 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		std::cout << std::endl << "---------- SUBJECT TEST ----------" << std::endl << std::endl;
		Intern	someRandomIntern;
		AForm*	rrf;
		try
		{
			rrf = someRandomIntern.makeForm("Robotomy Request Form", "Bender");
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		delete rrf;
	}
	{
		std::cout << std::endl << "---------- INVALID TEST ----------" << std::endl << std::endl;
		Intern	intern;
		AForm	*a;
		AForm	*b;
		AForm	*c;

		try
		{
			a = intern.makeForm("", "");
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			b = intern.makeForm("invalid", "");
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			c = intern.makeForm("robotomy request", "");
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "---------- INTERN CLASS TEST ----------" << std::endl << std::endl;
		Bureaucrat	bure("Bure", 1);
		Intern	intern;
		AForm	*a;
		AForm	*b;
		AForm	*c;

		a = intern.makeForm("Shrubbery Creation Form", "home");
		b = intern.makeForm("Robotomy Request Form", "Rob");
		c = intern.makeForm("Presidential Pardon Form", "Bob");

		std::cout << std::endl << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl << std::endl;

		try
		{
			bure.signForm(*a);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bure.signForm(*b);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bure.signForm(*c);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl << std::endl;

		try
		{
			bure.executeForm(*a);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bure.executeForm(*b);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bure.signForm(*c);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
	}
	return (0);
}
