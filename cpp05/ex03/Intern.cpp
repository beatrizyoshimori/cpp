


#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::Intern(const Intern &obj)
{
	std::cout << "Intern copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Intern&	Intern::operator=(const Intern &obj)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)obj;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

static AForm	*makePresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm		*(*f[])(std::string) = {makePresidentialPardonForm, makeRobotomyRequestForm, makeShrubberyCreationForm};
	std::string	validNames[] = {"Presidential Pardon Form", "Robotomy Request Form", "Shrubbery Creation Form"};

	for (int i = 0; i < 3; ++i)
		if (name == validNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (f[i](target));
		}
	std::cout << "Invalid form name!" << std::endl;
	return (NULL);
	throw Intern::InvalidFormName();
}

const char	*Intern::InvalidFormName::what(void) const throw()
{
	return ("Invalid form name!");
}
