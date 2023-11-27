

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixed_value;
		static const int	fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &f);
		~Fixed(void);
		Fixed & operator = (const Fixed &f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif