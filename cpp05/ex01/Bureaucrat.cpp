/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:37:56 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/17 21:14:28 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : _name(newName)
{
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = newGrade;
	std::cout << "Bureaucrat constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		const_cast<std::string &>(this->_name) = obj.getName();
		this->_grade = obj.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(int value)
{
	if (this->_grade - value < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= value;
}

void	Bureaucrat::decrementGrade(int value)
{
	if (this->_grade + value > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += value;
}

void	Bureaucrat::signForm(Form &f)
{
	if (f.getIsSigned() == true)
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because it's already signed" << std::endl;
		return ;
	}
	f.beSigned(*this);
	if (f.getIsSigned() == true)
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because the grade is too low" << std::endl;
}


std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& obj)
{
	lhs << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (lhs);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}