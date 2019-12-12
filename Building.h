/*Julia Zeng
EC 327 PA 3
Building.h*/

#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include "GameObject.h"
#include "Point2D.h"
using namespace std;


class Building : public GameObject
{

private:
	unsigned int pokemon_count = 0;

public: 
	void AddOnePokemon();
	
	void RemoveOnePokemon();
	
	void ShowStatus();
	
	bool ShouldBeVisible();

	Building();
	
	Building(char in_code, int in_id, Point2D in_loc) ;


	friend class PokemonCenter;
	
};




#endif 