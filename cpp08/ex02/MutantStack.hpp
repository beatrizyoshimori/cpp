/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:11:03 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/28 20:11:31 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <list>
#include <cstdlib>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {};
		MutantStack(const MutantStack &mutant) : std::stack<T>(mutant){}
		MutantStack	&operator=(const MutantStack &mutant)
		{
			if (this != &mutant)
				std::stack<T>::operator=(mutant);
			return (*this);
		}
		~MutantStack(void) {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void)
		{
			return (this->c.begin());
		}
		iterator	end(void)
		{
			return (this->c.end());
		}
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator	begin(void) const
		{
			return (this->c.cbegin());
		}
		const_iterator	end(void) const
		{
			return (this->c.cend());
		}
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin(void)
		{
			return std::stack<T>::c.rbegin();
		};
		reverse_iterator	rend(void)
		{
			return std::stack<T>::c.rend();
		};
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	rbegin(void) const
		{
			return std::stack<T>::c.rbegin();
		};
		const_reverse_iterator	rend(void) const
		{
			return std::stack<T>::c.rend();
		};
};

#endif
