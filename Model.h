/*Julia Zeng
EC 327 PA 3
Model.h*/

#ifndef MODEL_H
#define MODEL_H

#include <iostream>

#include "Pokemon.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"
#include <list>
#include <iterator>
#include <string>
#include "Input_Handling.h"

using namespace std;


class Model
{
private:
	int time;
	// GameObject* object_ptrs[10];
	// int num_objects = 8;
	// Pokemon* pokemon_ptrs[10];
	// int num_pokemon = 2;
	// PokemonCenter* center_ptrs[10];
	// int num_centers = 2;
	// PokemonGym* gym_ptrs[10];
	// int num_gyms = 2;

//Included for PA4
	// int num_rivals = 2; 
	// Rival* rival_ptrs[10];


	//create linked lists
	list<GameObject*> Object_ptrs;
	list<Pokemon*> Pokemon_ptrs;
	list<PokemonCenter*> PokemonCenter_ptrs;
	list<PokemonGym*> PokemonGym_ptrs;
	list<Rival*> Rival_ptrs;
	list<GameObject*> Active_ptrs; 
	list<BattleArena*> BattleArena_ptrs; 
//



public: 
	Model();

	~Model();

	Pokemon* GetPokemonPtr(int id);

	PokemonCenter* GetPokemonCenterPtr(int id);

	PokemonGym* GetPokemonGymPtr(int id);

	BattleArena* GetBattleArenaPtr(int id);

	bool Update();

	void Display(View& view);

	void ShowStatus();

	int GetTime();

//Included for PA4
	Rival* GetRivalPtr(int id);
	//Create a BattleArena Object to get the location of it


	list<GameObject*>::iterator Object_it; 
	// = Object_ptrs.begin();
	list<PokemonCenter*>::iterator center_it;
	 // = PokemonCenter_ptrs.begin();
	list<PokemonGym*>::iterator gym_it;
	 // = PokemonGym_ptrs.begin();
	list<Pokemon*>::iterator pokemon_it;
	 // = Pokemon_ptrs.begin();
	list<Rival*>::iterator rival_it;
	 // = Rival_ptrs.begin();
	list<GameObject*>::iterator active_it;

	list<BattleArena*>::iterator arena_it;

	void NewCommand(char type, int ID1, int x, int y);
//

};



#endif
