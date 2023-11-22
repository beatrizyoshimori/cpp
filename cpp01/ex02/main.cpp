/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:52:34 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/21 21:29:18 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory address of string: " << &str << std::endl
		<< "Memory address of stringPTR: " << &stringPTR << std::endl
		<< "Memory address of stringREF: " << &stringREF << std::endl
		<< "Value of string: " << str << std::endl
		<< "Value pointed to by stringPTR: " << *stringPTR << std::endl
		<< "Value pointed to by stringREF: " << stringREF << std::endl;
}
