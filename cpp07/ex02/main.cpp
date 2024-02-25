#include "Array.hpp"

int main(int, char**)
{
	Array<int>	a;
	Array<int>	b(0);

	try
	{
		a[0] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		b[0] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "a size: " << a.size() << std::endl;
	std::cout << "a address: " << a.getArray() << std::endl;
	std::cout << "b size: " << b.size() << std::endl;
	std::cout << "b address: " << b.getArray() << std::endl;
	
	Array<int>	numbers(50);
	int			*mirror = new int[50];

	srand(time(NULL));
	for (int i = 0; i < 50; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	Array<int>	tmp = numbers;
	Array<int>	test(tmp);

	for (int i = 0; i < 50; i++)
	{
		if (mirror[i] != numbers[i] || mirror[i] != tmp[i] || mirror[i] != test[i])
		{
			std::cerr << "Didn't save the same value!" << std::endl;
			return (1);
		}
	}
	std::cout << std::endl << "[25] before:" << std::endl;
	std::cout << "mirror[25]: " << mirror[25] << std::endl;
	std::cout << "numbers[25]: " << numbers[25] << std::endl;
	std::cout << "tmp[25]: " << tmp[25] << std::endl;
	std::cout << "test[25]: " << test[25] << std::endl;
	mirror[25] = 1;
	numbers[25] = 2;
	tmp[25] = 3;
	test[25] = 4;
	std::cout << std::endl << "[25] after:" << std::endl;
	std::cout << "mirror[25]: " << mirror[25] << std::endl;
	std::cout << "numbers[25]: " << numbers[25] << std::endl;
	std::cout << "tmp[25]: " << tmp[25] << std::endl;
	std::cout << "test[25]: " << test[25] << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		numbers[50] = 0;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < 50; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return (0);
}