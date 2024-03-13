/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:22:36 by byoshimo          #+#    #+#             */
/*   Updated: 2024/03/05 18:24:24 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iomanip>

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	if (this != &obj)
		*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
		this->_database = obj._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

static bool	isWhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

static void	ltrim(std::string &str)
{
	size_t	i = 0;

	while (i < str.size() && isWhitespace(str[i]))
		i++;
	str = str.substr(i);
}

static void	rtrim(std::string &str)
{
	size_t	i = str.size();

	while (i > 0 && isWhitespace(str[i - 1]))
		i--;
	str = str.substr(0, i);
}

static void	trim(std::string &str)
{
	ltrim(str);
	rtrim(str);
}

void	BitcoinExchange::loadDatabase(void)
{
	std::ifstream	file("files/data.csv");
	if (!file)
		throw std::runtime_error(RED "Couldn't open database file." RESET);
	
	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		t_date	date;
		if (isFormatValid(line, date, ',') && isDateValid(date, line) && isRateValid(date, line))
			this->_database[date.fullDate] = date.rate;
	}
	file.close();
}

void	BitcoinExchange::convert(std::string filename)
{
	std::ifstream	file(filename);
	if (!file)
		throw std::runtime_error(RED "Couldn't open input file." RESET);

	std::string	line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error(RED "Error: invalid header." RESET);
	while (std::getline(file, line))
	{
		t_date	date;
		if (isFormatValid(line, date, '|') && isDateValid(date, line) && isValueValid(date, line))
			printConversion(date);
	}
	file.close();
}

void	BitcoinExchange::printConversion(t_date &date)
{
	std::map<std::string, std::string>::iterator	itB = this->_database.begin();
	std::map<std::string, std::string>::iterator	itE = this->_database.end();
	for (; itE != itB; itE--)
	{
		if (date.fullDate >= itE->first)
			break ;
	}
	float	result = setValue(date.rate) * setValue(itE->second);
	std::cout << BLUE << date.fullDate << RESET << " => " << YELLOW << date.rate << RESET << " bitcoins = " << std::fixed << std::setprecision(2) << GREEN << result << RESET << std::endl;
}

bool	BitcoinExchange::isFormatValid(std::string &line, t_date &date, char delimiter)
{
	date.fullDate = line.substr(0, line.find(delimiter));
	trim(date.fullDate);
	std::istringstream	is(line);
	std::getline(is, date.year, '-');
	if (!is || date.year.size() == 0)
	{
		std::cerr << RED "Error: bad input => " << line << RESET << std::endl;
		return (false);
	}
	std::getline(is, date.month, '-');
	if (!is || date.month.size() == 0)
	{
		std::cerr << RED "Error: bad input => " << line << RESET << std::endl;
		return (false);
	}
	std::getline(is, date.day, delimiter);
	if (!is || date.day.size() == 0)
	{
		std::cerr << RED "Error: bad input => " << line << RESET << std::endl;
		return (false);
	}
	std::getline(is, date.rate);
	trim(date.rate);
	if (date.rate.size() == 0)
	{
		std::cerr << RED "Error: bad input => " << line << RESET << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isDateValid(t_date &date, std::string line)
{
	if (!validateDate(date))
	{
		std::cerr << RED "Error: bad input => " << line << RESET << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::validateDate(t_date &date)
{
	if (date.fullDate < "2009-01-02")
		return (false);
	if (!validateDigits(date.year) || !validateDigits(date.month) || !validateDigits(date.day))
		return (false);

	int	year = setDate(date.year);
	int	month = setDate(date.month);
	int	day = setDate(date.day);

	if (month < 1 || month > 12)
		return (false);

	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return (false);
	return (true);
}

bool	BitcoinExchange::validateDigits(std::string &date)
{
	size_t	i = 0;
	while (date[i] == ' ')
		i++;
	for (; i < date.size(); i++)
	{
		if (!isdigit(date[i]))
		{
			while (date[i] == ' ')
				i++;
			if (date[i])
				return (false);
		}
	}
	return (true);
}

int	BitcoinExchange::setDate(std::string &dateStr)
{
	std::istringstream	toInt(dateStr);
	int	date;
	toInt >> date;
	return (date);
}

float	BitcoinExchange::setValue(std::string &valueStr)
{
	std::istringstream	toFloat(valueStr);
	float	value;
	toFloat >> value;
	return (value);
}

bool	BitcoinExchange::isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool	BitcoinExchange::isRateValid(t_date &date, std::string line)
{
	bool	hasDot = false;
	size_t	i = 0;
	if (date.rate[i] == '+')
		i++;
	for (; i < date.rate.size(); i++)
	{
		if ((!isdigit(date.rate[i]) && date.rate[i] != '.') || (date.rate[i] == '.' && hasDot == true))
		{
			std::cerr << RED "Error: bad input => " << line << RESET << std::endl;
			return (false);
		}
		if (date.rate[i] == '.')
			hasDot = true;
	}
	return (true);
}

bool	BitcoinExchange::isValueValid(t_date &date, std::string line)
{
	std::istringstream	toFloat(date.rate);
	float	value;
	toFloat >> value;

	if (value < 0)
	{
		std::cerr << RED "Error: not a positive number => " << line << RESET << std::endl;
		return (false);
	}
	else if (value > 1000)
	{
		std::cerr << RED "Error: too large a number => " << line << RESET << std::endl;
		return (false);
	}

	size_t i = 0;
	bool	hasDot = false;
	if (date.rate[i] == '+')
		i++;
	for (; i < date.rate.size(); i++)
	{
		if ((!isdigit(date.rate[i]) && date.rate[i] != '.') || (date.rate[i] == '.' && hasDot == true))
		{
				std::cerr << RED "Error: bad input => " << line << RESET << std::endl;
				return (false);
		}
		if (date.rate[i] == '.')
			hasDot = true;
	}
	return (true);
}
