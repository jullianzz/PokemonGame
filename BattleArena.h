/*Julia Zeng
EC 327 PA 4
BattleArena.h*/


#ifndef BATTLEARENA_H
#define BATTLEARENA_H

#include <iostream>
#include "Building.h"
using namespace std;

enum BattleArenaStates {
	RIVALS_AVAILABLE = '0',
	NO_RIVALS_AVAILABLE = '1'
};


class BattleArena : public Building
{
public:
	BattleArena() ;

	BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc);

	unsigned int GetNumRivalsRemaining();
	bool HasEnoughRivals();
	double GetDollarCost();
	unsigned int GetStaminaCost();
	bool IsAbleToFight(double budget, unsigned int stamina);
	bool Update();
	bool IsBeaten();
	void ShowStatus();
	void RemoveOneRival();
	// unsigned int GetPokemonCount();
	friend class Pokemon; //this is so the Pokemon can increment pokemon_count once inside the arena

private:
	unsigned int max_num_rivals = 3;
	unsigned int num_rivals_remaining = max_num_rivals;
	double dollar_cost_per_fight;
	unsigned int stamina_cost_per_fight;
	// unsigned int pokemon_count = 0;

};



#endif