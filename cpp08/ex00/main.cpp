/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:41:18 by byoshimo          #+#    #+#             */
/*   Updated: 2024/02/28 19:58:29 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	{
		std::cout << std::endl << "TEST 1 (LIST)" << std::endl;
		std::list<int>	lst;
		lst.push_back(-10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);

		int	value = 20;
		std::cout << "Value: 20" << std::endl;
		try
		{
			easyfind(lst, value);
			std::cout << "Value " << value << " found in list." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = 50;
		std::cout << "Value: 50" << std::endl;
		try
		{
			easyfind(lst, value);
			std::cout << "Value " << value << " found in list." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = 35;
		std::cout << "Value: 35" << std::endl;
		try
		{
			easyfind(lst, value);
			std::cout << "Value " << value << " found in list." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = 500;
		std::cout << "Value: 500" << std::endl;
		try
		{
			easyfind(lst, value);
			std::cout << "Value " << value << " found in list." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = -20;
		std::cout << "Value: -20" << std::endl;
		try
		{
			easyfind(lst, value);
			std::cout << "Value " << value << " found in list." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST 1 (VECTOR)" << std::endl;
		std::vector<int>	vec;
		vec.push_back(-10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);

		int	value = 20;
		std::cout << "Value: 20" << std::endl;
		try
		{
			easyfind(vec, value);
			std::cout << "Value " << value << " found in vector." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = 50;
		std::cout << "Value: 50" << std::endl;
		try
		{
			easyfind(vec, value);
			std::cout << "Value " << value << " found in vector." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = 35;
		std::cout << "Value: 35" << std::endl;
		try
		{
			easyfind(vec, value);
			std::cout << "Value " << value << " found in vector." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = 500;
		std::cout << "Value: 500" << std::endl;
		try
		{
			easyfind(vec, value);
			std::cout << "Value " << value << " found in vector." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = -20;
		std::cout << "Value: -20" << std::endl;
		try
		{
			easyfind(vec, value);
			std::cout << "Value " << value << " found in vector." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST 1 (DEQUE)" << std::endl;
		std::deque<int>	deq;
		deq.push_back(-10);
		deq.push_back(20);
		deq.push_back(30);
		deq.push_back(40);
		deq.push_back(50);

		int	value = 20;
		std::cout << "Value: 20" << std::endl;
		try
		{
			easyfind(deq, value);
			std::cout << "Value " << value << " found in deque." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = 50;
		std::cout << "Value: 50" << std::endl;
		try
		{
			easyfind(deq, value);
			std::cout << "Value " << value << " found in deque." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = 35;
		std::cout << "Value: 35" << std::endl;
		try
		{
			easyfind(deq, value);
			std::cout << "Value " << value << " found in deque." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = 500;
		std::cout << "Value: 500" << std::endl;
		try
		{
			easyfind(deq, value);
			std::cout << "Value " << value << " found in deque." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		value = -20;
		std::cout << "Value: -20" << std::endl;
		try
		{
			easyfind(deq, value);
			std::cout << "Value " << value << " found in deque." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
