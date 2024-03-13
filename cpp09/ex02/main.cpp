#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: wrong number of arguments!\nUsage: ./PmergeMe [parameters]" << std::endl;
		return (1);
	}
	PmergeMe	merge;
	try
	{
		merge.sort(argc, argv);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
