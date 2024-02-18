#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	{
		std::cout << "SUBJECT TEST" << std::endl << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << std::endl << "TEST INT" << std::endl << std::endl;
		int	a = 4;
		int	b = 5;
		std::cout << "Before swap:" << std::endl << "a = " << a <<", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After swap:" << std::endl << "a = " << a <<", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	{
		std::cout << std::endl << "TEST STRING" << std::endl << std::endl;
		std::string a = "oi";
		std::string b = "tchau";
		std::cout << "Before swap:" << std::endl << "a = " << a <<", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After swap:" << std::endl << "a = " << a <<", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	{
		std::cout << std::endl << "TEST FLOAT" << std::endl << std::endl;
		float a = 3.987;
		float b = 4.321;
		std::cout << "Before swap:" << std::endl << "a = " << a <<", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After swap:" << std::endl << "a = " << a <<", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	{
		std::cout << std::endl << "TEST DOUBLE" << std::endl << std::endl;
		double a = -0.987;
		double b = -0.765;
		std::cout << "Before swap:" << std::endl << "a = " << a <<", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After swap:" << std::endl << "a = " << a <<", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	{
		std::cout << std::endl << "TEST POINTER" << std::endl << std::endl;
		std::string str = "oi";
		std::string *a = NULL;
		std::string *b = &str;
		std::cout << "Before swap:" << std::endl << "a = " << a <<", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After swap:" << std::endl << "a = " << a <<", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	return (0);
}
