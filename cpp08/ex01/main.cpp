/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:02:11 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/28 20:02:37 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	{
		std::cout << std::endl << "TEST 1 (subject)" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "TEST 2 (size 0)" << std::endl;
		Span	span;

		try
		{
			span.addNumber(5);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			span.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			span.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST 3 (size 1)" << std::endl;
		Span	span(1);

		try
		{
			span.addNumber(5);
			std::cout << "Integers vector: " << span.getInteger(0) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			span.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			span.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST 4 (size > 1)" << std::endl;
		Span	span(10);

		span.addNumber(5);
		span.addNumber(0);
		span.addNumber(27);
		span.addNumber(90);
		span.addNumber(-3);
		span.addNumber(987);
		span.addNumber(-43);
		span.addNumber(765);
		span.addNumber(65);
		span.addNumber(-22);

		std::cout << "Integers vector: ";
		for (unsigned int i= 0; i < span.getSize(); i++)
			std::cout << span.getInteger(i) << (i < span.getSize() - 1 ? ", " : "\n");

		try
		{
			span.addNumber(2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "TEST 5 (addNumbers)" << std::endl;
		Span				span(10);
		std::vector<int>	vec;

		vec.push_back(5);
		vec.push_back(0);
		vec.push_back(27);
		vec.push_back(90);
		vec.push_back(-3);
		vec.push_back(987);
		vec.push_back(-43);
		vec.push_back(765);
		vec.push_back(65);
		vec.push_back(-22);

		std::cout << "Vector: ";
		for (unsigned int i= 0; i < vec.size(); i++)
			std::cout << vec[i] << (i < vec.size() - 1 ? ", " : "\n");

		try
		{
			span.addNumbers(vec.begin(), vec.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Integers vector: ";
		for (unsigned int i= 0; i < span.getSize(); i++)
			std::cout << span.getInteger(i) << (i < span.getSize() - 1 ? ", " : "\n");
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "TEST 6 (copy)" << std::endl;
		Span	span(3);

		span.addNumber(0);
		span.addNumber(1);
		span.addNumber(-100);
		
		Span	spanOpCopy = span;
		Span	spanCopy(span);

		std::cout << "Integers vector: ";
		for (unsigned int i = 0; i < span.getSize(); i++)
			std::cout << span.getInteger(i) << (i < span.getSize() - 1 ? ", " : "\n");
		std::cout << "OpCopy Integers vector: ";
		for (unsigned int i = 0; i < spanOpCopy.getSize(); i++)
			std::cout << spanOpCopy.getInteger(i) << (i < spanOpCopy.getSize() - 1 ? ", " : "\n");
		std::cout << "Copy Integers vector: ";
		for (unsigned int i = 0; i < spanCopy.getSize(); i++)
			std::cout << spanCopy.getInteger(i) << (i < spanCopy.getSize() - 1 ? ", " : "\n");
		std::cout << std::endl << "DEEP COPY TEST" << std::endl;
		span.setInteger(0, 15);
		spanOpCopy.setInteger(0, -200);
		spanCopy.setInteger(0, 9);
		std::cout << "Integers vector: ";
		for (unsigned int i = 0; i < span.getSize(); i++)
			std::cout << span.getInteger(i) << (i < span.getSize() - 1 ? ", " : "\n");
		std::cout << "OpCopy Integers vector: ";
		for (unsigned int i = 0; i < spanOpCopy.getSize(); i++)
			std::cout << spanOpCopy.getInteger(i) << (i < spanOpCopy.getSize() - 1 ? ", " : "\n");
		std::cout << "Copy Integers vector: ";
		for (unsigned int i = 0; i < spanCopy.getSize(); i++)
			std::cout << spanCopy.getInteger(i) << (i < spanCopy.getSize() - 1 ? ", " : "\n");
		std::cout << std::endl << "Shortest span" << std::endl;
		std::cout << "Span: " << span.shortestSpan() << std::endl;
		std::cout << "SpanOpCopy: " << spanOpCopy.shortestSpan() << std::endl;
		std::cout << "SpanCopy: " << spanCopy.shortestSpan() << std::endl;
		std::cout << std::endl << "Longest span" << std::endl;
		std::cout << "Span: " << span.longestSpan() << std::endl;
		std::cout << "SpanOpCopy: " << spanOpCopy.longestSpan() << std::endl;
		std::cout << "SpanCopy: " << spanCopy.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "TEST 7 (size 20000)" << std::endl;
		Span	span(20000);

		for (unsigned int i = 0; i < 20000; i++)
			span.addNumber(i);

		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
}
