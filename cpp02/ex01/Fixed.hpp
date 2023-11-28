

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed_value;
		static const int	fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &f);
		Fixed & operator = (const Fixed &f);
		~Fixed(void);
		Fixed(const int number);
		Fixed(const float number);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& lhs, const Fixed& f);

#endif