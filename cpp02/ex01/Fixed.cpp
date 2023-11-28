

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_value = 0;
	return ;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &f)
		*this = f;
}

Fixed &Fixed::operator = (const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->fixed_value = f.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_value = number << Fixed::fractional_bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_value = (int)roundf(number * (1 << Fixed::fractional_bits));
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_value / (1 << Fixed::fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->fixed_value / (1 << Fixed::fractional_bits));
}

std::ostream& operator<<(std::ostream& lhs, const Fixed& f)
{
	lhs << f.toFloat();
	return (lhs);
}
