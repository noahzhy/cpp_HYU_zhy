#include "point2d.h"
#include <iostream>
using namespace std;

Point operator+(const Point& lhs, const Point& rhs) {
	cout<<"(" <<lhs.x_ + rhs.x_<<", "<<lhs.y_ + rhs.y_<<")"<<endl;

}
Point operator-(const Point& lhs, const Point& rhs) {
	cout<<"(" <<lhs.x_ - rhs.x_<<", "<<lhs.y_ - rhs.y_<<")"<<endl;

}
Point operator*(const Point& lhs, const Point& rhs) {
	cout<<"(" <<lhs.x_ * rhs.x_<<", "<<lhs.y_ * rhs.y_<<")"<<endl;

}
