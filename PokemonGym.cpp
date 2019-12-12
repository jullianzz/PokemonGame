/*Julia Zeng
EC 327 PA3
PokemonGym.cpp*/

#include <iostream>
#include "PokemonGym.h"
using namespace std;

PokemonGym::PokemonGym() : Building()
{
	display_code = 'G';
	state = NOT_BEATEN;
	max_number_of_training_units = 10;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = 1;
	dollar_cost_per_training_unit = 1.0;
	experience_points_per_training_unit = 2;
	
	cout << "PokemonGym default constructed" << endl;
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc)
	: Building('G', in_id, in_loc)
{
	max_number_of_training_units = max_training_units;
	num_training_units_remaining = max_training_units;
	stamina_cost_per_training_unit = stamina_cost;
	experience_points_per_training_unit = exp_points_per_unit;
	dollar_cost_per_training_unit = dollar_cost;
	state = NOT_BEATEN;

	cout << "PokemonGym constructed" << endl;
}

double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
	return dollar_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
	return stamina_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
	return num_training_units_remaining;
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
	if ( (stamina >= stamina_cost_per_training_unit * unit_qty) && (budget >= dollar_cost_per_training_unit * unit_qty) )
	{
		return true; 	//Pokemon can train
	}
	else 
		return false; //Pokemon cannot train
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
	if (training_units > num_training_units_remaining)
	//This is the number of experience points gained if there aren't enough training units at the gym
		{
			unsigned int temp = num_training_units_remaining;
			num_training_units_remaining = 0; 
			return temp * experience_points_per_training_unit;
		}
	else 
	//Experience points gained when there are enough training units at the gym
	{
		num_training_units_remaining -= training_units;
		return training_units * experience_points_per_training_unit;
	}
}

bool PokemonGym::Update()
{
	if (num_training_units_remaining == 0 && state == NOT_BEATEN)
	{
		state = BEATEN;
		display_code = 'g';
		cout << display_code << id_num << " has been beaten" << endl;
		return true;
	}
	else if (num_training_units_remaining == 0 && state == NOT_BEATEN)
	{
		display_code = 'g';
		cout << display_code << id_num << " has been beaten" << endl;
		return false;
	}
	else 
		return false;
}

bool PokemonGym::IsBeaten()
{
	if (num_training_units_remaining == 0)
		return true;
	else 
		return false; 
}

void PokemonGym::ShowStatus()
{
	cout << "Pokemon Gym Status: "; this->GameObject::ShowStatus();
	cout << "\n	" ; Building::ShowStatus();
	cout << "	Max number of training units: " << max_number_of_training_units << endl;
	cout << "	Stamina cost per training unit: " << stamina_cost_per_training_unit << endl;
	cout << "	Pokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
	cout << "	Experience points per training unit: " << experience_points_per_training_unit << endl;
	cout << "	" << num_training_units_remaining << " training unit(s) are remaining for this gym\n\n" ;
	
}
	



