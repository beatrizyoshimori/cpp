
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point(void);
		Point(Fixed const a, Fixed const b);
		Point(const Point &p);
		Point&	operator=(const Point &p);
		~Point(void);
};

#endif