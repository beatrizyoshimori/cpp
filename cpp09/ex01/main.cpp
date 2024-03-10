#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments!\nUsage: ./RPN <parameter>" << std::endl;
		return (1);
	}
	RPN	rpn;
	try
	{
		rpn.rpn(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
