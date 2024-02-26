/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:50:24 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/26 19:35:14 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int			a[] = {1, 2, 3, 4};
	float		b[] = {2.5, 3.7, 99.5, 10.3};
	std::string	c[] = {"oi", "tudo", "bem", "?"};
	const int	d[] = {9, 8, 7, 6};
	char		*e = NULL;

	std::cout << "TEST INT" << std::endl;
	::iter(a, 4, ::print);
	std::cout << std::endl << "TEST FLOAT" << std::endl;
	::iter(b, 4, ::print);
	std::cout << std::endl << "TEST STRING" << std::endl;
	::iter(c, 4, ::print);
	std::cout << std::endl << "TEST CONST INT" << std::endl;
	::iter(d, 4, ::print);
	std::cout << std::endl << "TEST NULL" << std::endl;
	::iter(e, 1, ::print);
}
