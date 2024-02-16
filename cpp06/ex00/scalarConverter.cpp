
#include "scalarConverter.hpp"

scalarConverter::scalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
	return ;
}

scalarConverter::scalarConverter(const scalarConverter &obj)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

scalarConverter&	scalarConverter::operator=(const scalarConverter &obj)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	(void)obj;
	return (*this);
}

scalarConverter::~scalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
	return ;
}
