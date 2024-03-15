/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:49:21 by byoshimo          #+#    #+#             */
/*   Updated: 2024/03/15 17:49:25 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

class PmergeMe
{
	private:
		int					_numberOfElements;
		int					_straggler;
		std::vector<int>	_unsortedVector;
		std::vector<int>	_sortedVector;
		std::vector<int>	_pendChainVector;
		std::deque<int>		_unsortedDeque;
		std::deque<int>		_sortedDeque;
		std::deque<int>		_pendChainDeque;

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &obj);
		PmergeMe& operator=(const PmergeMe &obj);
		~PmergeMe(void);

		void	sort(int argc, char** argv);
		void	validateParameters(int argc, char** argv);
		void	checkDuplicateNumbers(std::vector<int> vec);

		void	createAndSortMainChainVector(void);
		void	insertionVector(void);
		void	createAndSortMainChainDeque(void);
		void	insertionDeque(void);

		unsigned int	generateJacobsthalNumbers(unsigned int j0, unsigned int j1);
		void			printTime (clock_t start, clock_t end, size_t size, std::string type);
};

template <typename T>
void	printElements(T sorted)
{
	typename T::iterator	it = sorted.begin();
	typename T::iterator	itEnd = sorted.end();

	for (; it != itEnd; it++)
		std::cout << *it << (it != itEnd - 1 ? " " : "\n");
}

template <typename T>
void	foundStraggler(T &container, int &straggler)
{
	typename T::iterator	itStraggler;

	if (container.size() % 2)
	{
		itStraggler = container.end();
		itStraggler--;
		straggler = *itStraggler;
		container.pop_back();
	}
}

#endif
