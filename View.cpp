/*Julia Zeng
EC 327 PA 3
View.cpp*/

#include <iostream>
#include "View.h"


using namespace std;

View::View()
{
	size = 11;
	scale = 2;
	Point2D origin(0,0);
}

void View::Clear()
{
	for (int i=0; i< view_maxsize; i++)  //initializes grid array 
	{
		for (int j=0; j< view_maxsize; j++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

void View::Plot(GameObject* ptr)
{
	double x = ptr->GetLocation().x;
	double y = ptr->GetLocation().y;
	int out_x = 0;
	int out_y = 0;
	if (GetSubscripts(out_x, out_y, Point2D(x,y))) 
	{
		if (grid[out_x][out_y][0] == '.' && grid[out_x][out_y][1] == ' ')
		{
			ptr->DrawSelf(grid[out_x][out_y]);
			//cout << "yes" << endl;
		}
		else //There is already an object in that location
		{
			grid[out_x][out_y][0] = '*';
			grid[out_x][out_y][1] = ' ';
		}
	}
}

void View::Draw()
{

	for (int j = size; j >= 1; j--)
	{
		int yloc = (j-1)*scale;
		int doublescale = scale*2;
		if (yloc % doublescale == 0)
		{
			cout << yloc; 
			if (yloc < 10)
				cout << " " ;
		}
		else
			cout << "  ";
		for (int i = 1; i <= size; i++)
		{
			cout << grid[i][j][0] << grid[i][j][1] ;
		}

		cout << endl;
	}

	cout << "  " ;

	for (int j = 1; j <= size; j++)
	{
		int yloc = (j-1)*scale;
		int doublescale = scale*2;
		if (yloc % doublescale == 0)
		{
			cout << yloc; 
			if (yloc < 10)
				cout << " " ;
		}
		else
			cout << "  ";
	}

	cout << endl;
}


bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
	out_x = (location.x - origin.x)/scale + 1;
	out_y = (location.y - origin.y)/scale + 1;

	if ((out_x <= view_maxsize) && (out_x >= 0) && (out_y <= view_maxsize) && (out_y >= 0))
	{
		//cout << out_x << " " << out_y << endl;
 		return true; 
	}
	else 
		return false;

}

