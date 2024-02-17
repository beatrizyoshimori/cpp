/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:12:03 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/16 21:24:06 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments!" << std::endl;
		std::cout << "Usage: ./scalarConverter <value>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
