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

Span::Span(void) : _size(0)
{
	std::cout << "Span default constructor called" << std::endl;
	return ;
}

Span::Span(unsigned int N) : _size(N)
{
	std::cout << "Span constructor called" << std::endl;
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
	if (this != &obj)
	{
		this->_size = obj._size;
		for (unsigned int i = 0; i < obj._integers.size(); i++)
			this->_integers.push_back(obj._integers[i]);
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
	return ;
}

void	Span::addNumber(int number)
{
	if (!this->_size)
		throw std::runtime_error("Unable to add number. The integers vector size is 0.");
	else if (this->_size == this->_integers.size())
		throw std::runtime_error("Unable to add number. The integers vector is already full.");
	else
		this->_integers.push_back(number);
}

int	Span::shortestSpan(void)
{
	if (!this->_integers.size())
		throw std::runtime_error("No span can be found. The integers vector is empty.");
	else if (this->_integers.size() == 1)
		throw std::runtime_error("No span can be found. The integers vector has only one vector.");

	int	span = std::abs(this->_integers[0] - this->_integers[1]);

	for (unsigned int i = 0; i < this->_integers.size() - 1; i++)
	{
		for (unsigned int j = i + 1; j < this->_integers.size(); j++)
		{
			if (std::abs(this->_integers[i] - this->_integers[j]) < span)
				span = std::abs(this->_integers[i] - this->_integers[j]);
		}
	}
	return (span);
}

int	Span::longestSpan(void)
{
	if (!this->_integers.size())
		throw std::runtime_error("No span can be found. The integers vector is empty.");
	else if (this->_integers.size() == 1)
		throw std::runtime_error("No span can be found. The integers vector has only one vector.");

	int	max = this->_integers[0];
	int	min = this->_integers[0];

	for (unsigned int i = 1; i < this->_integers.size(); i++)
	{
		if (this->_integers[i] < min)
			min = this->_integers[i];
		else if (this->_integers[i] > max)
			max = this->_integers[i];
	}
	return (max - min);
}

void	Span::addNumbers(std::vector<int >::iterator b, std::vector<int >::iterator e)
{
	this->_integers.insert(this->_integers.end(), b, e);
}

unsigned int	Span::getSize(void) const
{
	return (this->_size);
}

int	Span::getInteger(unsigned int i) const
{
	return (this->_integers[i]);
}

void	Span::setInteger(unsigned int i, int integer)
{
	this->_integers[i] = integer;
}
