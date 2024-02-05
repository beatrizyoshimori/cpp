

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("Shrubbery Creation Form", 145, 137)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_target = obj.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return ;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::checkExecute(executor);

	std::ofstream	file((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::FailedToOpenFile();
	file << "   *\n";
	file << "  ***\n";
	file << " *****\n";
	file << "*******\n";
	file << "  ***\n";
	file << "  ***\n";
	file.close();
}

const char	*ShrubberyCreationForm::FailedToOpenFile::what(void) const throw()
{
	return ("Failed to open file!");
}
