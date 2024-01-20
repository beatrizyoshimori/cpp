/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:16:00 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/20 16:25:59 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceInFile.hpp"

void	check_arg(int argc)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments!" << std::endl
			<< "Usage: ./replace <filename> str_to_be_replaced str_to_replace" << std::endl;
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	check_arg(argc);
	ReplaceInFile	file(argv);
	file.replace_string(argv);
	return (0);
}
