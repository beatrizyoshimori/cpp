#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(void)
		{
			this->_array = NULL;
			this->_size = 0;
		}
		Array(unsigned int size)
		{
			this->_size = size;
			if (!size)
				this->_array = NULL;
			else
				this->_array = new T[size];
		}
		Array(const Array &obj)
		{
			if (this != &obj)
				*this = obj;
		}
		Array& operator=(const Array &obj)
		{

		}
		~Array();
};

Array::Array(/* args */)
{
}

Array::~Array()
{
}


#endif