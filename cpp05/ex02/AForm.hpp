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

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		AForm(void);
		AForm(std::string newName, int toSign, int toExecute);
		AForm(const AForm &obj);
		AForm& operator=(const AForm &obj);
		~AForm(void);

		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class FormNotSigned : public std::exception {
			public:
				const char *what(void) const throw();
		};

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getGradeSign(void) const;
		int				getGradeExecute(void) const;
		void			beSigned(const Bureaucrat &b);
		void			checkExecute(const Bureaucrat &b) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& lhs, const AForm& obj);

#endif