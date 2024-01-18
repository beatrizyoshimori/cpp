/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:07:51 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/17 21:07:14 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name(""), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

Form::Form(std::string newName, int toSign, int toExecute) : _name(newName), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	if (toSign < 1 || toExecute < 1)
		throw Form::GradeTooHighException();
	else if (toSign > 150 || toExecute > 150)
		throw Form::GradeTooLowException();
	const_cast<int &>(this->_gradeSign) = toSign;
	const_cast<int &>(this->_gradeExecute) = toExecute;
	std::cout << "Form constructor called" << std::endl;
	return ;
}

Form::Form(const Form &obj) : _name(obj.getName()), _isSigned(obj.getIsSigned()), _gradeSign(obj.getGradeSign()), _gradeExecute(obj.getGradeExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Form&	Form::operator=(const Form &obj)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		const_cast<std::string &>(this->_name) = obj.getName();
		this->_isSigned = obj.getIsSigned();
		const_cast<int &>(this->_gradeSign) = obj.getGradeSign();
		const_cast<int &>(this->_gradeExecute) = obj.getGradeExecute();
	}
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int	Form::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
		this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& lhs, const Form& obj)
{
	lhs << "Form " << obj.getName() << ", is signed? " << obj.getIsSigned() << ", grade required to sign: "
		<< obj.getGradeSign() << ", grade required to execute: " << obj.getGradeExecute();
	return (lhs);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}
