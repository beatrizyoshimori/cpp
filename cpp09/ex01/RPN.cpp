#include "RPN.hpp"

RPN::RPN(void)
{
	std::cout << "RPN default constructor called." << std::endl;
}

RPN::RPN(const RPN &obj)
{
	if (this != &obj)
		*this = obj;
}

RPN& RPN::operator=(const RPN &obj)
{
	if (this != &obj)
		this->_numbers = obj._numbers;
	return *this;
}

RPN::~RPN(void)
{
	std::cout << "RPN destructor called." << std::endl;
}

void	RPN::rpn(std::string str)
{
	validateParameter(str);
	for (size_t i = 0; str[i]; i++)
	{
		if (std::isdigit(str[i]))
		{
			addNumber(str[i]);
			if (str[i + 1] != ' ')
				throw std::runtime_error(RED "Error: Invalid parameter." RESET);
		}
		else if (str[i] == '*' || str[i] == '/' || str[i] == '-' || str[i] == '+')
			calculate(str[i]);
	}
	if (this->_numbers.size() != 1)
		throw std::runtime_error (RED "Error: Invalid parameter." RESET);
	std::cout << GREEN << this->_numbers.top() << RESET << std::endl;
}

void	RPN::validateParameter(std::string str)
{
	if (!str[0] || str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::runtime_error(RED "Error: Invalid parameter." RESET);
}

void	RPN::addNumber(char p)
{
	this->_numbers.push((int)p - '0');
}

void	RPN::calculate(char p)
{
	int	size = this->_numbers.size();
	if (size < 2)
		throw std::runtime_error(RED "Error: Invalid parameter." RESET);
	int	num = this->_numbers.top();
	this->_numbers.pop();
	if (p == '+')
		this->_numbers.top() += num;
	else if (p == '-')
		this->_numbers.top() -= num;
	else if (p == '*')
		this->_numbers.top() *= num;
	else
	{
		if (num == 0)
			throw std::runtime_error (RED "Error: Couldn't divide by 0." RESET);
		this->_numbers.top() /= num;
	}
}

const std::stack<int>	&RPN::getNumbers(void) const
{
	return (this->_numbers);
}
