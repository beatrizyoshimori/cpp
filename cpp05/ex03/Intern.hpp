


#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &obj);
		Intern& operator=(const Intern &obj);
		~Intern(void);

		class InvalidFormName : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		AForm *makeForm(std::string formName, std::string formTarget);
};

#endif