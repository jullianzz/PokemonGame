/*Julia Zeng
EC 327 PA 4
BattleArena.cpp*/

#include "BattleArena.h"

BattleArena::BattleArena() : Building('A', 1, Point2D(0,0))
{
	max_num_rivals = 3;
	num_rivals_remaining = max_num_rivals;
	dollar_cost_per_fight = 4;
	stamina_cost_per_fight = 3;
	state = RIVALS_AVAILABLE;

	cout << "BattleArena default constructed" << endl;
}


BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, 
	int in_id, Point2D in_loc) : Building('A', in_id, in_loc)
{
	max_num_rivals = max_rivals;
	num_rivals_remaining = max_num_rivals;
	stamina_cost_per_fight = stamina_cost;
	dollar_cost_per_fight = dollar_cost; 
	id_num = in_id; 
	location = in_loc;
	state = RIVALS_AVAILABLE; 

	cout << "BattleArena constructed" << endl;

}

unsigned int BattleArena::GetNumRivalsRemaining()
{
	return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals()
{
	if (num_rivals_remaining >= 1)
		return true;
	else
		return false;
}

double BattleArena::GetDollarCost()
{
	return dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost()
{
	return stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina)
{
	if (budget >= dollar_cost_per_fight)
	{
		if (stamina >= stamina_cost_per_fight)
			return true;
		else
		{
			cout << "Not enough stamina to fight" << endl;
			return false; 
		}
	}
	else 
	{
		cout << "Not enough pokedollars to fight" << endl;
		return false;
	}
}

bool BattleArena::Update()
{
	if (num_rivals_remaining > 0)
	{
		return false;
	}
	else if (num_rivals_remaining <= 0 && IsBeaten())
	{
		return true;
	}
	else
		return false;

}

bool BattleArena::IsBeaten()
{
	if (num_rivals_remaining == 0)
		return true;
	else
		return false;
}

void BattleArena::ShowStatus()
{
	cout << "BattleArena status: " ;
	this->GameObject::ShowStatus() ;
	cout << endl << "\t";
	this->Building::ShowStatus();
	cout << "\tMax number of rivals: " << max_num_rivals << endl;
	cout << "\tStamina cost per fight: " << stamina_cost_per_fight << endl;
	cout << "\tPokemon dollar per fight: " << dollar_cost_per_fight << endl;
	cout << "\tNumber of rivals remaining: " << num_rivals_remaining << endl;

}

void BattleArena::RemoveOneRival()
{
	num_rivals_remaining --; 
}
// unsigned int BattleArena::GetPokemonCount()
// {
// 	return pokemon_count;
// }


