

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &obj);
		Serializer& operator=(const Serializer &obj);
		~Serializer(void);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif