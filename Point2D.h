/*Julia Zeng
EC 327 PA3
Point2D.h*/
//updated

#ifndef POINT_2D_H
#define POINT_2D_H

#include "Vector2D.h"

#include <cmath>
#include <iostream>
using namespace std;

// Class definition for Point2D
class Point2D
{
public:

	//Public members
	double x;

	double y;

	Point2D();	

	Point2D(double in_x, double in_y);


};

double GetDistanceBetween(Point2D p1, Point2D p2);

ostream& operator<<(ostream& out, const Point2D& p1);

Point2D operator+(Point2D& p1, Vector2D& v1);

Vector2D operator-(Point2D& p1, Point2D& p2);

#endif 