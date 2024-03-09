/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:22:41 by byoshimo          #+#    #+#             */
/*   Updated: 2024/03/05 18:27:31 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		std::cout << "Usage: ./btc [filename]" << std::endl;
		return (1);
	}
	BitcoinExchange	btc;
	try
	{
		btc.loadDatabase();
		btc.convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
