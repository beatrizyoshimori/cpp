/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:16:00 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/22 21:59:38 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	(void) argc;
	std::ifstream	infile(argv[1]);
	std::string		str;
	std::string		line;
	
	while (infile)
	{
		std::getline(infile, line);
		std::cout << line << std::endl;
	}
	return (0);
}
