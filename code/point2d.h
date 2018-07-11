#ifndef __point2d__
#define __point2d__
#include <iostream>
using namespace std;

struct Point
{
	int x_, y_;
	Point();
	Point(int x, int y){
		x_ = x;
		y_ = y;
	};
	Point(const Point& p);
	explicit Point(int c);
	
};

Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const Point& lhs, const Point& rhs);

#endif
