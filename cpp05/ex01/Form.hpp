/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:01:59 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/17 20:14:06 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		Form(void);
		Form(std::string newName, int toSign, int toExecute);
		Form(const Form &obj);
		Form& operator=(const Form &obj);
		~Form(void);

		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExecute(void) const;
		void		beSigned(const Bureaucrat &b);
};

std::ostream& operator<<(std::ostream& lhs, const Form& obj);

#endif