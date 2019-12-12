/*Julia Zeng
EC 327 PA3
Point2D.cpp*/
//Updated
#include <iostream>
#include "Point2D.h"
using namespace std;

//Constructors
Point2D::Point2D() 	//Default constructor
{
	x = 0.0;
	y = 0.0;
}

Point2D::Point2D(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
	double x1 = p1.x;
	double y1 = p1.y;

	double x2 = p2.x;
	double y2 = p2.y;
	double d = sqrt( pow(x1-x2,2) + pow(y1-y2,2) ); 
	return d; 
}


ostream& operator<<(ostream& out, const Point2D& p1)
{
	out << "(" << p1.x << "," << p1.y << ")" ;
	return out;
}

// Addition operator
Point2D operator+(Point2D& p1, Vector2D& v1)
{
	double in_x = p1.x + v1.x;
	double in_y = p1.y + v1.y;
	//create new Point2D object
	return Point2D(in_x, in_y);
}

Vector2D operator-(Point2D& p1, Point2D& p2)
{
	double in_x = p1.x - p2.x;
	double in_y = p1.y - p2.y; 
	//create new Vector2D object
	return Vector2D(in_x, in_y);
}