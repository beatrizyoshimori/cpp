/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:07:51 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/17 21:07:14 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name(""), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
	return ;
}

AForm::AForm(std::string newName, int toSign, int toExecute) : _name(newName), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "AForm constructor called" << std::endl;
	if (toSign < 1 || toExecute < 1)
		throw AForm::GradeTooHighException();
	else if (toSign > 150 || toExecute > 150)
		throw AForm::GradeTooLowException();
	const_cast<int &>(this->_gradeSign) = toSign;
	const_cast<int &>(this->_gradeExecute) = toExecute;
	return ;
}

AForm::AForm(const AForm &obj) : _name(obj.getName()), _isSigned(obj.getIsSigned()), _gradeSign(obj.getGradeSign()), _gradeExecute(obj.getGradeExecute())
{
	std::cout << "AForm copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

AForm&	AForm::operator=(const AForm &obj)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		const_cast<std::string &>(this->_name) = obj.getName();
		this->_isSigned = obj.getIsSigned();
		const_cast<int &>(this->_gradeSign) = obj.getGradeSign();
		const_cast<int &>(this->_gradeExecute) = obj.getGradeExecute();
	}
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
	return ;
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int	AForm::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeSign())
	{
		std::cout << b.getName() << " could't sign " << this->getName() << std::endl;
		throw AForm::GradeTooLowException();
	}
	this->_isSigned = true;
}

void	AForm::checkExecute(const Bureaucrat &b) const
{
	if (!this->getIsSigned() || b.getGrade() > this->getGradeExecute())
	{
		std::cout << b.getName() << " could't execute " << this->getName() << std::endl;
		if (!this->getIsSigned())
			throw AForm::FormNotSigned();
		if (b.getGrade() > this->getGradeExecute())
			throw AForm::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& lhs, const AForm& obj)
{
	std::string	isSigned;

	if (obj.getIsSigned() == true)
		isSigned = "Yes";
	else
		isSigned = "No";
	lhs << "AForm " << obj.getName() << ", is signed? " << isSigned << ", grade required to sign: "
		<< obj.getGradeSign() << ", grade required to execute: " << obj.getGradeExecute();
	return (lhs);
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

const char	*AForm::FormNotSigned::what(void) const throw()
{
	return ("Form not signed!");
}
