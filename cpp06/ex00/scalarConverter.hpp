

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

class scalarConverter
{
	public:
		scalarConverter(void);
		scalarConverter(const scalarConverter &obj);
		scalarConverter& operator=(const scalarConverter &obj);
		~scalarConverter(void);

		static void	convert(std::string str);
};

#endif