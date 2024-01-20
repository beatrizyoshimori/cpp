/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:29:00 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/20 19:29:03 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_value = 0;
	return ;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_value = number << Fixed::_fractional_bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_value = (int)roundf(number * (1 << Fixed::_fractional_bits));
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &f)
		*this = f;
}

Fixed&	Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->_fixed_value = f.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixed_value / (1 << Fixed::_fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixed_value / (1 << Fixed::_fractional_bits));
}

std::ostream& operator<<(std::ostream& lhs, const Fixed& f)
{
	lhs << f.toFloat();
	return (lhs);
}

Fixed	Fixed::operator+(const Fixed& f)
{
	return (this->toFloat() + f.toFloat());
}

Fixed	Fixed::operator-(const Fixed& f)
{
	return (this->toFloat() - f.toFloat());
}

Fixed	Fixed::operator*(const Fixed& f)
{
	return (this->toFloat() * f.toFloat());
}

Fixed	Fixed::operator/(const Fixed& f)
{
	return (this->toFloat() / f.toFloat());
}

bool	Fixed::operator>(const Fixed& f) const
{
	return (this->toFloat() > f.toFloat());
}

bool	Fixed::operator<(const Fixed& f) const
{
	return (this->toFloat() < f.toFloat());
}

bool	Fixed::operator>=(const Fixed& f) const
{
	return (this->toFloat() >= f.toFloat());
}

bool	Fixed::operator<=(const Fixed& f) const
{
	return (this->toFloat() <= f.toFloat());
}

bool	Fixed::operator==(const Fixed& f) const
{
	return (this->toFloat() == f.toFloat());
}

bool	Fixed::operator!=(const Fixed& f) const
{
	return (this->toFloat() != f.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	this->_fixed_value++;
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed	f(*this);
	this->_fixed_value++;
	return (f);
}

Fixed&	Fixed::operator--(void)
{
	this->_fixed_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	f(*this);
	this->_fixed_value--;
	return (f);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}
