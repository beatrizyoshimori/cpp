

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);
		~RobotomyRequestForm(void);

		std::string	getTarget(void) const;
		void		execute(Bureaucrat const & executor) const;
};

#endif