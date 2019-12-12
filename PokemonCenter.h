/*Julia Zeng
EC 327 PA3
PokemonCenter.h*/
//updated

#ifndef POKEMON_CENTER_H
#define POKEMON_CENTER_H

enum PokemonCenterStates {
	STAMINA_POINTS_AVAILABLE = '0',
	NO_STAMINA_POINTS_AVAILABLE = '1' };


#include "Building.h"


class PokemonCenter : public Building
{
private:
	unsigned int stamina_capacity = 50;
	unsigned int num_stamina_points_remaining = stamina_capacity; //init value is stamina_capacity
	double dollar_cost_per_stamina_point;
	
	
public:
	PokemonCenter();

	PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc);

	bool HasStaminaPoints();
	
	unsigned int GetNumStaminaPointsRemaining();
	
	bool CanAffordStaminaPoints(unsigned int stamina_points, double budget);
	
	double GetDollarCost(unsigned int stamina_points);
	
	unsigned int DistributeStamina(unsigned int points_needed);
	
	bool Update();
	
	void ShowStatus();
		
		
};


#endif
