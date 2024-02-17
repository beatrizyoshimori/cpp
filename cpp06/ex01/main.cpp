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
		std::cout << "TEST 2 (INVALID POINTER)" << std::endl;
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
