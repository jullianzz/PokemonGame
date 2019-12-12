/*Julia Zeng
EC 327 PA 3
Building.cpp*/
//updated

#include <iostream>
#include "Building.h"

using namespace std;

Building::Building() : GameObject('B')
{	
	cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
	cout << "Building constructed" << endl;
}


void Building::AddOnePokemon()
{
	pokemon_count+=1;
}

void Building::RemoveOnePokemon()
{
	pokemon_count-=1;
}

void Building::ShowStatus()
{
	if (pokemon_count == 1)
		cout << pokemon_count << " pokemon is in this building" << endl;
	else if (pokemon_count == 0 || pokemon_count > 1)
		cout << pokemon_count << " pokemon are in this building" << endl;
	else 
		cout << "Error! There is a negative number of pokemon in this building!" << endl ;
}

bool Building::ShouldBeVisible()
{
	return true;
}

