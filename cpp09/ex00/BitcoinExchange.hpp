/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:22:38 by byoshimo          #+#    #+#             */
/*   Updated: 2024/03/05 18:25:53 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"

class	BitcoinExchange
{
	typedef struct	s_date
	{
		std::string	fullDate;
		std::string	year;
		std::string	month;
		std::string	day;
		std::string	rate;
	}	t_date;

	private:
		std::map<std::string, std::string>	_database;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange& operator=(const BitcoinExchange &obj);
		~BitcoinExchange(void);

		void	loadDatabase(void);
		void	convert(std::string filename);
		void	printConversion(t_date &date);

		bool	isFormatValid(std::string &line, t_date &date, char delimiter);
		bool	isDateValid(t_date &date, std::string line);
		bool	validateDate(t_date &date);
		bool	validateDigits(std::string &date);
		int		setDate(std::string &dateStr);
		float	setValue(std::string &valueStr);
		bool	isLeapYear(int year);
		bool	isRateValid(t_date &date, std::string line);
		bool	isValueValid(t_date &date, std::string line);
};

#endif