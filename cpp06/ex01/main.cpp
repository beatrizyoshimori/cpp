#include "Serializer.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		Data a = (Data){.value= 10};
		Data *d = &a;
		uintptr_t ptr = Serializer::serialize(d);
		Data *res = Serializer::deserialize(ptr);
		std::cout << "Original ptr value: " << d->value << std::endl;
		std::cout << "Original ptr address: " << d << std::endl;
		std::cout << "Deserialized ptr value: " << res->value << std::endl;
		std::cout << "Deserialized ptr address: " << res << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "TEST 2 (RANDOM)" << std::endl;
		srand(time(NULL));
		Data		*ptr1 = new Data;
		ptr1->value = (std::rand() % 1000);
		uintptr_t	uintPtr1;
		Data		*deserializePtr1;

		uintPtr1 = Serializer::serialize(ptr1);
		deserializePtr1 = Serializer::deserialize(uintPtr1);

		std::cout << "Data's value through Data original pointer:\t"
			 << ptr1->value << std::endl;
		std::cout << "Data's value through Data deserialized pointer:\t"
			<< deserializePtr1->value << std::endl;
		std::cout << std::endl;
		delete ptr1;
	}
	{
		std::cout << "TEST 3 (INVALID POINTER)" << std::endl;
		Data		*ptr = NULL;
		std::cout << "Created a Data object NULL" << std::endl;
		uintptr_t	uintPtr;
		Data		*deserializePtr;

		uintPtr = Serializer::serialize(ptr);
		deserializePtr = Serializer::deserialize(uintPtr);

		if (deserializePtr == NULL)
			std::cout << "Deserialized pointer is NULL" << std::endl;
		else
			std::cout << "Deserialized pointer is not NULL" << std::endl;
	}
}
