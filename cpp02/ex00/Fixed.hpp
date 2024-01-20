/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:29:33 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/20 19:29:36 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixed_value;
		static const int	_fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &f);
		~Fixed(void);
		Fixed & operator = (const Fixed &f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif