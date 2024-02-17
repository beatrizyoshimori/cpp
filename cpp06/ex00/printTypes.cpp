/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:29:59 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/16 21:18:27 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printChar(int c)
{
	std::cout << "char:\t" << "'" << static_cast<char>(c) << "'" << std::endl;
	std::cout << "int:\t" << static_cast<int>(c) << std::endl;
	std::cout << "float:\t" << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double:\t" << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	printInt(long double number)
{
	int	integer = number;

	std::cout << "char:\t";
	if (integer >= 0 && integer <= 255)
	{
		if (isprint(integer))
			std::cout << "'" << static_cast<char>(integer) << "'" << std::endl;
		else
			std::cout << "non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int:\t" << static_cast<int>(number) << std::endl;
	std::cout << "float:\t" << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double:\t" << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl;
}

void	printFloat(long double number, int decimals)
{
	double	floor = static_cast<double>(std::floor(number));

	std::cout << "char:\t";
	if (floor >= 0 && floor <= 255)
	{
		if (isprint(floor))
			std::cout << "'" << static_cast<char>(floor) << "'" << std::endl;
		else
			std::cout << "non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int:\t";
	if (floor >= -2147483649 && floor <= 2147483647)
	{
		if (floor < 0)
			floor++;
		std::cout << static_cast<int>(floor) << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float:\t" << std::fixed << std::setprecision(decimals) << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double:\t" << std::fixed << std::setprecision(decimals) << static_cast<double>(number) << std::endl;
}

void	printDouble(long double number, int decimals)
{
	double	floor = static_cast<double>(std::floor(number));

	std::cout << "char:\t";
	if (floor >= 0 && floor <= 255)
	{
		if (isprint(floor))
			std::cout << "'" << static_cast<char>(floor) << "'" << std::endl;
		else
			std::cout << "non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int:\t";
	if (floor >= -2147483649 && floor <= 2147483647)
	{
		if (floor < 0)
			floor++;
		std::cout << static_cast<int>(floor) << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float:\t";
	if (number < std::numeric_limits<float>::max() &&
		number > -std::numeric_limits<float>::max())
		std::cout << std::fixed << std::setprecision(decimals) << static_cast<float>(number) << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "double:\t" << std::fixed << std::setprecision(decimals) << static_cast<double>(number) << std::endl;
}

void	printLiterals(int i, std::string str)
{
	std::cout << "char:\t" << "impossible" << std::endl;
	std::cout << "int:\t" << "impossible" << std::endl;
	if (i > 3)
		str[str.size() - 1] = '\0';
	std::cout << "float:\t" << str << "f" << std::endl;
	std::cout << "double:\t" << str << std::endl;
}

void	printImpossible(void)
{
	std::cout << "char:\t" << "impossible" << std::endl;
	std::cout << "int:\t" << "impossible" << std::endl;
	std::cout << "float:\t" << "impossible" << std::endl;
	std::cout << "double:\t" << "impossible" << std::endl;
	return ;
}
