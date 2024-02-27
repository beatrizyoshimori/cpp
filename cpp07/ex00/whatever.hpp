/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:49:20 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/26 21:30:10 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T &min(T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T>
const T &min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

template <typename T>
T &max(T &a, T &b)
{
	return (a > b ? a : b);
}

template <typename T>
const T &max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

#endif