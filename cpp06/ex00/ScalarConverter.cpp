/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:12:10 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/16 21:19:50 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &obj)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
	return ;
}

static bool	isChar(std::string str)
{
	if (str.size() > 1 || !isprint(str[0]) || (str.size() == 1 && isdigit(str[0])))
		return (false);
	printChar(str[0]);
	return (true);
}

static bool	isInt(std::string str)
{
	int		i;
	double	number;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while(str[i])
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	number = atof(str.c_str());
	if (number > 2147483647 || number < -2147483648)
		return (false);
	printInt(number);
	return (true);
}

static bool	isFloat(std::string str)
{
	int			dot = 0;
	int			i = 0;
	int			size = (int)str.size() - 1;
	int			decimals = -1;
	bool		hasDot = false;
	long double	number;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while (i < size)
	{
		if (str[i] != '.' && !isdigit(str[i]))
			return (false);
		if (str[i] == '.')
		{
			dot++;
			hasDot = true;
		}
		if (hasDot)
			decimals++;
		i++;
	}
	if (decimals == -1)
		decimals = 1;
	if (!isdigit(str[i - 1]) || str[i] != 'f' || dot > 1 || str[0] == '.' || str[i - 1] == '.')
		return (false);
	number = atof(str.c_str());
	if (number > std::numeric_limits<float>::max() ||
		number < -std::numeric_limits<float>::max())
		return (false);
	printFloat(number, decimals);
	return (true);
}

static bool	isDouble(std::string str)
{
	int			dot = 0;
	int			i = 0;
	int			decimals = -1;
	bool		hasDot = false;
	long double	number;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while(str[i])
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
		{
			dot++;
			hasDot = true;
		}
		if (hasDot)
			decimals++;
		i++;
	}
	if (decimals == -1)
		decimals = 1;
	if (dot > 1 || str[0] == '.' || str[i - 1] == '.')
		return (false);
	number = atof(str.c_str());
	if (number > std::numeric_limits<double>::max() ||
		number < -std::numeric_limits<double>::max())
		return (false);
	printDouble(number, decimals);
	return (true);
}

static bool	isPseudoLiterals(std::string str)
{
	std::string pseudoLiterals[]= {
		"inf",
		"+inf",
		"-inf",
		"nan",
		"nanf",
		"inff",
		"+inff",
		"-inff"
	};

	for (int i = 0; i < 8 ; i++)
		if (pseudoLiterals[i] == str)
		{
			printLiterals(i, str);
			return (true);
		}
	return (false);
}

void	ScalarConverter::convert(std::string str)
{
	if (str.size() == 0)
	{
		printImpossible();
		return ;
	}
	if (isChar(str))
		return ;
	else if (isInt(str))
		return ;
	else if (isFloat(str))
		return ;
	else if (isDouble(str))
		return ;
	else if (isPseudoLiterals(str))
		return ;
	else
		printImpossible();
}
