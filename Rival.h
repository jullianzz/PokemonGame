/*Julia Zeng
EC 327 PA 4
Rival.h*/


#ifndef RIVAL_H
#define RIVAL_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BattleArena.h"
#include "GameObject.h"
using namespace std; 

enum RivalStates {
	ALIVE_RIVAL = '0',
	FAINTED_RIVAL = '1'
};

class Rival : public GameObject
{
public:
	//Rival();
	Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, Point2D in_loc); 

	void TakeHit(double physical_damage, double magical_damage, double defense);
	double get_phys_dmg();
	double get_magic_dmg();
	double get_defense();
	double get_health();
	bool Update();
	void ShowStatus();
	bool IsAlive();
	BattleArena* GetCurrentArenaPtr();
	string GetName();
	bool ShouldBeVisible();

	friend class Model;


protected:
	double health = 20;
	double physical_damage = 5;
	double magical_damage = 4;
	double defense = 15;
	bool is_in_arena; 
	string name;
	double speed; 
	BattleArena* current_arena; 


	
};



#endif