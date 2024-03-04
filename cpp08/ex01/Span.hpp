/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:03:24 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/28 20:07:11 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_integers;

	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &obj);
		Span& operator=(const Span &obj);
		~Span(void);

		void	addNumber(int number);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	addNumbers(std::vector<int >::iterator b, std::vector<int >::iterator e);

		unsigned int	getSize(void) const;
		int				getInteger(unsigned int i) const;
		void			setInteger(unsigned int i, int integer);

};

#endif
