/*Julia Zeng
EC 327 PA3
PokemonGym.h*/

#ifndef POKEMON_GYM_H
#define POKEMON_GYM_H

#include "Building.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include <iostream>
using namespace std;


enum PokemonGymStates {
	NOT_BEATEN = '0',
	BEATEN = '1' };
	

class PokemonGym : public Building 
{
private: 
	unsigned int num_training_units_remaining;
	unsigned int max_number_of_training_units;
	unsigned int stamina_cost_per_training_unit;
	unsigned int dollar_cost_per_training_unit;
	unsigned int experience_points_per_training_unit;
	
public:
	PokemonGym();
	
	PokemonGym(unsigned int, unsigned int, double, unsigned int, int, Point2D);
	
	double GetDollarCost(unsigned int unit_qty);
	
	unsigned int GetStaminaCost(unsigned int unit_qty);
	
	unsigned int GetNumTrainingUnitsRemaining();
	
	bool IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina);
	
	unsigned int TrainPokemon(unsigned int training_units);
	
	bool Update();
	
	bool IsBeaten();
	
	void ShowStatus();
	
};


#endif 
