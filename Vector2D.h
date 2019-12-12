/*Julia Zeng
EC 327 PA3
Vector2D.h*/
//updated


#ifndef VECTOR_2D_H
#define VECTOR_2D_H

//#include "Point2D.h"

#include <iostream>
using namespace std;

#include <cmath>

// Class definition for Vector2D
class Vector2D
{
public:
	//Public members
	double x;

	double y; 


	//Constuctors

	Vector2D(); //default constructor


	Vector2D(double in_x, double in_y);


};


ostream& operator<<(ostream& out, const Vector2D& v1);

Vector2D operator*(Vector2D& v1, double d);

Vector2D operator/(Vector2D& v1, double d);



#endif 