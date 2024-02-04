

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Form", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Form", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("Robotomy Form", 72, 45)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_target = obj.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::checkExecute(executor);

	std::cout << "*** DRILLING NOISES ***" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized sucessfully." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}
