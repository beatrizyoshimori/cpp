/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:38:56 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/26 21:38:57 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(void)
		{
			this->_array = NULL;
			this->_size = 0;
		}
		Array(unsigned int size)
		{
			this->_size = size;
			if (!size)
				this->_array = NULL;
			else
				this->_array = new T[size];
		}
		Array(const Array &obj)
		{
			this->_array = NULL;
			this->_size = 0;
			if (this != &obj)
				*this = obj;
		}
		Array& operator=(const Array &obj)
		{
			if (this != &obj)
			{
				if (this->_array)
					delete[] this->_array;
				new(this) Array(obj._size);
				for (unsigned int i = 0; i < obj._size; i++)
					this->_array[i] = obj._array[i];
			}
			return (*this);
		}
		~Array()
		{
			if (this->_array)
				delete[] this->_array;
			this->_size = 0;
			this->_array = NULL;
			return ;
		}
		T	&operator[](int index)
		{
			if (index < 0 || index >= (int)this->_size)
				throw (std::out_of_range("Error: Index out of range."));
			return (this->_array[index]);
			
		}
		const T	&operator[](int index) const
		{
			if (index < 0 || index >= (int)this->_size)
				throw (std::out_of_range("Error: Index out of range."));
			return (this->_array[index]);
		}
		unsigned int	size(void)
		{
			return (this->_size);
		}
		T	*getArray(void) const
		{
			return (this->_array);
		}
};

#endif