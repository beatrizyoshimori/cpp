/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:50:20 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/26 18:55:21 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, size_t length, void (*f)(T&))
{
	if (array)
		for (size_t i = 0; i < length; i++)
			f(array[i]);
}

template <typename T>
void	iter(const T *array, size_t length, void (*f)(const T&))
{
	if (array)
		for (size_t i = 0; i < length; i++)
			f(array[i]);
}

template <typename T>
void	print(T &a)
{
	std::cout << a << std::endl;
}

#endif