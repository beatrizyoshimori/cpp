#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	std::cout << "PmergeMe default constructor called." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	if (this != &obj)
		*this = obj;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		this->_numberOfElements = obj._numberOfElements;
		this->_straggler = obj._straggler;
		this->_unsortedVector = obj._unsortedVector;
		this->_sortedVector = obj._sortedVector;
		this->_pendChainVector = obj._pendChainVector;
		this->_unsortedDeque = obj._unsortedDeque;
		this->_sortedDeque = obj._sortedDeque;
		this->_pendChainDeque = obj._pendChainDeque;
	}
	return *this;
}

PmergeMe::~PmergeMe(void)
{
	std::cout << "PmergeMe destructor called." << std::endl;
}

void	PmergeMe::sort(int argc, char** argv)
{
	validateParameters(argc, argv);
	std::cout << "Before:\t";
	printElements(this->_unsortedVector);

	clock_t	startVector = clock();

	this->_straggler = -1;
	foundStraggler(this->_unsortedVector, this->_straggler);
	createAndSortMainChainVector();
	insertionVector();

	clock_t	startDeque = clock();
	this->_straggler = -1;
	foundStraggler(this->_unsortedDeque, this->_straggler);
	createAndSortMainChainDeque();
	insertionDeque();

	clock_t	endDeque = clock();

	std::cout << GREEN <<"After (vector):\t" << RESET;
	printElements(this->_sortedVector);
	std::cout << GREEN <<"After (deque):\t" << RESET;
	printElements(this->_sortedDeque);
	printTime(startVector, startDeque, this->_unsortedVector.size(), "vector");
	printTime(startDeque, endDeque, this->_unsortedDeque.size(), "deque");
}

void	PmergeMe::validateParameters(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		if (!argv[i][0])
			throw std::runtime_error("Error: empty string.");
		if (str.find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error("Error: invalid parameter.");
		std::istringstream	toInt(argv[i]);
		unsigned int	number;
		toInt >> number;
		if (number > 2147483647)
			throw std::runtime_error("Error: too large a number.");
		this->_unsortedVector.push_back(number);
		this->_unsortedDeque.push_back(number);
	}
	checkDuplicateNumbers(this->_unsortedVector);
	this->_numberOfElements = this->_unsortedVector.size();
}

void	PmergeMe::checkDuplicateNumbers(std::vector<int> vec)
{
	std::vector<int>			vector;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	itEnd;
	std::vector<int>::iterator	itNext;

	vector = vec;
	std::sort(vector.begin(), vector.end());
	it = vector.begin();
	itEnd = vector.end();
	for (; it != itEnd; it++)
	{
		itNext = it;
		itNext++;
		if (itNext != itEnd)
			if (*it == *itNext)
				throw std::runtime_error("Error: Duplicate numbers.");
	}
}

void	PmergeMe::createAndSortMainChainVector(void)
{
	std::vector<int>::iterator	itNext;
	std::vector<int>::iterator	it = this->_unsortedVector.begin();
	std::vector<int>::iterator	itEnd = this->_unsortedVector.end();

	while (it != itEnd)
	{
		itNext = it;
		itNext++;
		if (*it > *itNext)
		{
			this->_sortedVector.insert(std::upper_bound(this->_sortedVector.begin(), \
				this->_sortedVector.end(), *it), *it);
			this->_pendChainVector.push_back(*itNext);
		}
		else
		{
			this->_sortedVector.insert(std::upper_bound(this->_sortedVector.begin(), \
				this->_sortedVector.end(), *itNext), *itNext);
			this->_pendChainVector.push_back(*it);
		}
		it += 2;
	}
	if (this->_straggler != -1)
	{
		this->_sortedVector.insert(std::upper_bound(this->_sortedVector.begin(), \
			this->_sortedVector.end(), this->_straggler), this->_straggler);
		this->_unsortedVector.push_back(this->_straggler);
	}
}

void	PmergeMe::insertionVector(void)
{
	unsigned int				j0 = 1;
	unsigned int				j1 = 1;
	unsigned int				erasedElements = 0;
	unsigned int				size = this->_pendChainVector.size();
	std::vector<int>::iterator	itPos = this->_pendChainVector.begin();

	if (size > 0)
		this->_sortedVector.insert(std::upper_bound(this->_sortedVector.begin(), \
				this->_sortedVector.end(), *itPos), *itPos);
	erasedElements++;
	while (erasedElements < size)
	{
		unsigned int	jacNumber = generateJacobsthalNumbers(j0, j1);
		j0 = j1;
		j1 = jacNumber;
		if (size < jacNumber)
		{
			itPos = this->_pendChainVector.end() - 1;
			jacNumber = size;
		}
		else
			itPos = this->_pendChainVector.begin() + jacNumber - 1;
		while (jacNumber > erasedElements)
		{
			this->_sortedVector.insert(std::upper_bound(this->_sortedVector.begin(), \
				this->_sortedVector.end(), *itPos), *itPos);
			erasedElements++;
			itPos--;
		}
	}
}

void	PmergeMe::createAndSortMainChainDeque(void)
{
	std::deque<int>::iterator	itNext;
	std::deque<int>::iterator	it = this->_unsortedDeque.begin();
	std::deque<int>::iterator	itEnd = this->_unsortedDeque.end();

	while (it != itEnd)
	{
		itNext = it;
		itNext++;
		if (*it > *itNext)
		{
			this->_sortedDeque.insert(std::upper_bound(this->_sortedDeque.begin(), \
				this->_sortedDeque.end(), *it), *it);
			this->_pendChainDeque.push_back(*itNext);
		}
		else
		{
			this->_sortedDeque.insert(std::upper_bound(this->_sortedDeque.begin(), \
				this->_sortedDeque.end(), *itNext), *itNext);
			this->_pendChainDeque.push_back(*it);
		}
		it += 2;
	}
	if (this->_straggler != -1)
	{
		this->_sortedDeque.insert(std::upper_bound(this->_sortedDeque.begin(), \
				this->_sortedDeque.end(), this->_straggler), this->_straggler);
		this->_unsortedDeque.push_back(this->_straggler);
	}
}

void	PmergeMe::insertionDeque(void)
{
	unsigned int				j0 = 1;
	unsigned int				j1 = 1;
	unsigned int				erasedElements = 0;
	unsigned int				size = this->_pendChainDeque.size();
	std::deque<int>::iterator	itPos = this->_pendChainDeque.begin();

	if (size > 0)
		this->_sortedDeque.insert(std::upper_bound(this->_sortedDeque.begin(), \
				this->_sortedDeque.end(), *itPos), *itPos);
	erasedElements++;
	while (erasedElements < size)
	{
		unsigned int	jacNumber = generateJacobsthalNumbers(j0, j1);
		j0 = j1;
		j1 = jacNumber;
		if (size < jacNumber)
		{
			itPos = this->_pendChainDeque.end() - 1;
			jacNumber = size;
		}
		else
			itPos = this->_pendChainDeque.begin() + jacNumber - 1;
		while (jacNumber > erasedElements)
		{
			this->_sortedDeque.insert(std::upper_bound(this->_sortedDeque.begin(), \
				this->_sortedDeque.end(), *itPos), *itPos);
			erasedElements++;
			itPos--;
		}
	}
}

unsigned int	PmergeMe::generateJacobsthalNumbers(unsigned int j0, unsigned int j1)
{
	return (2 * j0 + j1);
}

void	PmergeMe::printTime (clock_t start, clock_t end, size_t size, std::string type)
{
	double	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	double	usTime = time * 1000000.0;

	std::cout << "Time to process a range of " << GREEN << size << RESET
		<< " elements with std::" << YELLOW << type << RESET
		<< ": " << GREEN << usTime << RESET << " us" << std::endl;
}
