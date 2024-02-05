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
#include "Intern.hpp"

int	main(void)
{
	{
		std::cout << std::endl << "---------- SUBJECT TEST ----------" << std::endl << std::endl;
		Intern	someRandomIntern;
		AForm*	rrf;
		rrf = someRandomIntern.makeForm("Robotomy Request Form", "Bender");
		delete rrf;
	}
	{
		std::cout << std::endl << "---------- INVALID TEST ----------" << std::endl << std::endl;
		Intern	intern;
		AForm	*a;
		AForm	*b;
		AForm	*c;

		a = intern.makeForm("", "");
		b = intern.makeForm("invalid", "");
		c = intern.makeForm("robotomy request", "");
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

		bure.signForm(*a);
		bure.signForm(*b);
		bure.signForm(*c);

		std::cout << std::endl << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl << std::endl;

		bure.executeForm(*a);
		bure.executeForm(*b);
		bure.executeForm(*c);
		std::cout << std::endl;
	}
	return (0);
}
