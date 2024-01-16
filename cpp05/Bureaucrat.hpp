/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:23:12 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/16 18:52:58 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string newName, int newGrade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat& operator=(const Bureaucrat &obj);
		~Bureaucrat(void);

		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(int value);
		void				decrementGrade(int value);
};

#endif