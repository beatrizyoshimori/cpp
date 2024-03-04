/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:09:40 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/28 20:10:03 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	{
		std::cout << std::endl << "TEST 1 (subject)" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << std::endl << "TEST 2 (copy)" << std::endl;
		MutantStack<int>	a;
		a.push(21);
		a.push(24);
		a.push(-42);
		a.push(42);
		a.push(43);
		MutantStack<int>	b(a);
		MutantStack<int>	c = b;

		MutantStack<int>::iterator	itA = a.begin();
		MutantStack<int>::iterator	iteA = a.end();
		std::cout << "MutantStack A(ORIGINAL), size: " << a.size() <<	" -> [";
		while (itA != iteA)
		{
			std::cout << *itA << (itA + 1 != iteA ? ", " : "]");
			++itA;
		}
		std::cout << std::endl;
		std::cout << "top: " << a.top() << std::endl;
		MutantStack<int>::iterator	itB = a.begin();
		MutantStack<int>::iterator	iteB = a.end();

		std::cout << "MutantStack B(COPY CONSTRUCTOR), size: " << b.size() <<	" -> [";
		while (itB != iteB)
		{
			std::cout << *itB << (itB + 1 != iteB ? ", " : "]");
			++itB;
		}
		std::cout << std::endl;
		std::cout << "top: " << b.top() << std::endl;

		MutantStack<int>::iterator	itC = a.begin();
		MutantStack<int>::iterator	iteC = a.end();
		std::cout << "MutantStack C(ASSIGNMENT OPERATOR OVERLOADING), size: " << c.size() <<	" -> [";
		while (itC != iteC)
		{
			std::cout << *itC << (itC + 1 != iteC ? ", " : "]");
			++itC;
		}
		std::cout << std::endl;
		std::cout << "top: " << c.top() << std::endl;

		std::cout << std::endl << "Deep copy test:" << std::endl;
		a.push(1207);
		itA = a.begin();
		iteA = a.end();
		std::cout << "MutantStack A, size: " << a.size() <<	" -> [";
		while (itA != iteA)
		{
			std::cout << *itA << (itA + 1 != iteA ? ", " : "]");
			++itA;
		}
		std::cout << std::endl;
		b.pop();
		b.pop();
		itB = b.begin();
		iteB = b.end();
		std::cout << "MutantStack B, size: " << b.size() <<	" -> [";
		while (itB != iteB)
		{
			std::cout << *itB << (itB + 1 != iteB ? ", " : "]");
			++itB;
		}
		std::cout << std::endl;
		c.pop();
		itC = c.begin();
		iteC = c.end();
		std::cout << "MutantStack C, size: " << c.size() <<	" -> [";
		while (itC != iteC)
		{
			std::cout << *itC << (itC + 1 != iteC ? ", " : "]");
			++itC;
		}
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "TEST 3 (iterators)" << std::endl;
		MutantStack<int>	mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();
		std::cout << "MutantStack (NORMAL ITERATOR),	size: " << mstack.size() <<	" -> [";
		while (it != ite)
		{
			std::cout << *it << (it + 1 != ite ? ", " : "]");
			++it;
		}
		std::cout << std::endl;

		MutantStack<int>::reverse_iterator	rIt = mstack.rbegin();
		MutantStack<int>::reverse_iterator	rIte = mstack.rend();
		std::cout << "MutantStack (REVERSE ITERATOR),	size: " << mstack.size() <<	" -> [";
		while (rIt != rIte)
		{
			std::cout << *rIt << (rIt + 1 != rIte ? ", " : "]");
			++rIt;
		}
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "TEST 3 (list)" << std::endl;
		MutantStack<int>	mstack;
		std::list<int>		list;

		for (int i = 0; i < 10; i++)
		{
			mstack.push(i);
			list.push_back(i);
		}

		MutantStack<int>::iterator	itMStack = mstack.begin();
		MutantStack<int>::iterator	iteMStack = mstack.end();
		std::cout << "MutantStack,	size: " << mstack.size() <<	" -> [";
		while (itMStack != iteMStack)
		{
			std::cout << *itMStack << (itMStack + 1 != iteMStack ? ", " : "]");
			++itMStack;
		}
		std::cout << std::endl;

		std::list<int>::iterator	itList = list.begin();
		std::list<int>::iterator	iteList = list.end();
		std::cout << "Container List,	size: " << list.size() <<	" -> [";
		while (itList != iteList)
			std::cout << *itList << (++itList != iteList ? ", " : "]");
		std::cout << std::endl;
	}
}
