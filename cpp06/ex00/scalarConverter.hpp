/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:12:15 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/16 21:23:50 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cmath>

class scalarConverter
{
	private:
		scalarConverter(void);
		scalarConverter(const scalarConverter &obj);
		scalarConverter& operator=(const scalarConverter &obj);
		~scalarConverter(void);

	public:
		static void	convert(std::string str);
};

void	printChar(int c);
void	printInt(long double number);
void	printFloat(long double number, int decimals);
void	printDouble(long double number, int decimals);
void	printLiterals(int i, std::string str);
void	printImpossible(void);

#endif