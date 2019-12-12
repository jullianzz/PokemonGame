/*Julia Zeng
EC 327 PA3
PokemonCenter.cpp*/

#include "PokemonCenter.h"

	
PokemonCenter::PokemonCenter() : Building()
{
	display_code = 'C';
	stamina_capacity = 100;
	num_stamina_points_remaining = stamina_capacity;
	dollar_cost_per_stamina_point = 5;
	state = STAMINA_POINTS_AVAILABLE; 
	
	cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc) : Building('C', in_id, in_loc)
{
	dollar_cost_per_stamina_point = stamina_cost;
	stamina_capacity = stamina_cap;
	num_stamina_points_remaining = stamina_capacity; 
	state = STAMINA_POINTS_AVAILABLE;
	
	cout << "PokemonCenter constructed" << endl;
	
}

bool PokemonCenter::HasStaminaPoints()
{
	if (num_stamina_points_remaining >= 1)
		return true;
	else 
		return false;
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining()
{
	return num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
	if (budget >= (dollar_cost_per_stamina_point * stamina_points))
		return true;
	else 
		return false;
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
	return (stamina_points * dollar_cost_per_stamina_point);
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
	if (num_stamina_points_remaining >= points_needed)
	{
		num_stamina_points_remaining -= points_needed;
		return points_needed; 
	}
	
	else 
	{
		unsigned int temp = num_stamina_points_remaining;
		num_stamina_points_remaining = 0;
		return temp; 
	}
}

bool PokemonCenter::Update()
{
	if (num_stamina_points_remaining == 0 && state == STAMINA_POINTS_AVAILABLE)		//Stamina points are depleted
	{
		state = NO_STAMINA_POINTS_AVAILABLE; 
		display_code = 'c';
		cout << "PokemonCenter " << id_num << " has ran out of stamina points" << endl;
		return true;
	}

	else if (num_stamina_points_remaining == 0 && state == NO_STAMINA_POINTS_AVAILABLE)
	{
		cout << "PokemonCenter " << id_num << " has ran out of stamina points" << endl;
		return false;
	}
	
	else 						// Stamina points are not depleted
	{
		state = STAMINA_POINTS_AVAILABLE;
		//cout << "PokemonCenter has " << num_stamina_points_remaining << " stamina points remaining." << endl;
		return false; 
	}
}

void PokemonCenter::ShowStatus()
{
	cout << "Pokemon Center Status: " ; GameObject::ShowStatus(); cout << endl;
	cout << "	" ; Building::ShowStatus();
	cout << "	Pokemon dollars per stamina point: " << dollar_cost_per_stamina_point << endl;
	cout << "	has " << num_stamina_points_remaining << " stamina point(s) remaining.\n\n" ;
	
}
		
	
