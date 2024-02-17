#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "TEST 1" << std::endl;

	Base	*ptrA = new A();
	Base	&refA = *ptrA;
	std::cout << "Generated A type class." << std::endl;
	Base	*ptrB = new B();
	Base	&refB = *ptrB;
	std::cout << "Generated B type class." << std::endl;
	Base	*ptrC = new C();
	Base	&refC = *ptrC;
	std::cout << "Generated C type class." << std::endl << std::endl;

	std::cout << "Identify pointers:" << std::endl;
	identify(ptrA);
	identify(ptrB);
	identify(ptrC);
	std::cout << std::endl;

	std::cout << "Identify references:" << std::endl;
	identify(refA);
	identify(refB);
	identify(refC);

	delete ptrA;
	delete ptrB;
	delete ptrC;
	std::cout << std::endl;

	std::cout << "TEST 2 (RANDOM)" << std::endl;

	Base	*ptr = generate();

	std::cout << "Identify pointer:" << std::endl;
	identify(ptr);

	std::cout << std::endl;

	std::cout << "Identify reference:" << std::endl;
	Base	&ref = *ptr;
	identify(ref);

	delete ptr;
	std::cout << std::endl;

	std::cout << "TEST 3 (CLASS D)" << std::endl;

	class D : public Base {};
	Base	*ptrD = new D();
	Base	&refD = *ptrD;
	std::cout << "Generated D type class." << std::endl << std::endl;

	std::cout << "Identify pointer:" << std::endl;
	identify(ptrD);

	std::cout << std::endl;

	std::cout << "Identify reference:" << std::endl;
	identify(refD);

	delete(ptrD);
	std::cout << std::endl;

	std::cout << "TEST 4 (INVALID POINTER)" << std::endl;

	Base	*ptrNull = NULL;
	std::cout << "Generated a NULL pointer." << std::endl << std::endl;

	std::cout << "Identify pointer:" << std::endl;
	identify(ptrNull);
	
	return (0);
}
