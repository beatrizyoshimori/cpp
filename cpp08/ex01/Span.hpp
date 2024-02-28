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

class Span
{
	private:
		/* data */
	public:
		Span(void);
		Span(const Span &obj);
		Span& operator=(const Span &obj);
		~Span(void);
};

#endif
