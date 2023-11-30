

#include "Point.hpp"

Point::Point(void)
{
	this->x = 0;
	this->y = 0;
}

Point::Point(Fixed const a, Fixed const b)
{
	this->x = a;
	this->y = b;
}

Point::Point(const Point &p)
{
	if (this != &p)
		*this = p;
}

Point&	Point::operator=(const Point &p)
{
	if (this != &p)
		this = p;
	return (*this);
}

Point::~Point(void)
{
	return ;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{

}
