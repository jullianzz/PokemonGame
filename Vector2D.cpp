/*Julia Zeng
EC 327 PA3
Vector2D.cpp*/
//updated


#include <iostream>
#include "Vector2D.h"
using namespace std;


Vector2D::Vector2D() //default constructor
{
	x = 0.0;
	y = 0.0;
}

Vector2D::Vector2D(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}


ostream& operator<<(ostream& out, const Vector2D& v1)
{
	out << "<" << v1.x << "," << v1.y << ">" ;
	return out;
}

Vector2D operator*(Vector2D& v1, double d)
{
	double x = v1.x * d;
	double y = v1.y * d; 
	return Vector2D(x,y);
}

Vector2D operator/(Vector2D& v1, double d)
{
	if (d == 0)
	{
		return v1; 
	}
	else 
	{
		double x = v1.x / d;
		double y = v1.y / d; 
		return Vector2D(x,y);
	}
}
