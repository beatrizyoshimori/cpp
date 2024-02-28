/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:03:15 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/28 20:05:32 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	std::cout << "Span default constructor called" << std::endl;
	return ;
}

Span::Span(const Span &obj)
{
	std::cout << "Span copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Span&	Span::operator=(const Span &obj)
{
	std::cout << "Span copy assignment operator called" << std::endl;
	(void)obj;
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
	return ;
}
