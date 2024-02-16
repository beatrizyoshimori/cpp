

#include "scalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments!" << std::endl;
		std::cout << "Usage: ./scalarConverter <value>" << std::endl;
		return (1);
	}
	scalarConverter::convert(argv[1]);
	return 0;
}
