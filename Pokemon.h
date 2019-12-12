/*Julia Zeng
EC 327 PA 3
Pokemon.h*/


#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include "GameObject.h"
#include <string>
#include "Point2D.h"
#include "Vector2D.h"
#include <cstdlib>
#include <ctime>
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include  <cmath>
#include "Rival.h"
#include "BattleArena.h"



using namespace std;

enum PokemonStates {
	STOPPED = '0',
	MOVING = '1',
	EXHAUSTED = '2',
	IN_GYM = '3',
	IN_CENTER = '4',
	MOVING_TO_GYM = '5',
	MOVING_TO_CENTER = '6',
	TRAINING_IN_GYM = '7',
	RECOVERING_STAMINA = '8',

	//Included for PA4 :
	IN_ARENA = '9',
	MOVING_TO_ARENA = 'a',
	BATTLE = 'b',
	FAINTED = 'c'
	//
};


class Pokemon : public GameObject
{
public:
	Pokemon();
	Pokemon(char in_code);
	Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
	bool IsExhausted();

	void StartMoving(Point2D dest);
	void ShowStatus();
	bool Update();
	bool UpdateLocation();
	void SetupDestination(Point2D dest);
	void StartMovingToCenter(PokemonCenter* center);
	void StartMovingToGym(PokemonGym* gym);
	void StartTraining(unsigned int num_training_units);
	void StartRecoveringStamina(unsigned int num_stamina_points);
	void Stop();
	bool ShouldBeVisible();
	string GetName();
	~Pokemon();


//Included for PA4
	Pokemon(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, Point2D in_loc); 
	bool isAlive();
	void TakeHit(double physical_damage, double magical_damage, double defense);
	void ReadyBattle(Rival* in_target);
	bool StartBattle();
	void StartMovingToArena(BattleArena* arena);
	void SetTarget(Rival* rival_ptr);
	Rival* GetTarget();
//

friend class Model;

//Included for PA4 :
protected:
	double health = 20;
	double store_health = health;
	double physical_damage = 5;
	double magical_damage = 4;
	double defense = 15;
	Rival* target;
	BattleArena* current_arena; 
	bool is_in_arena = false;
//



private:
	double speed; //distance per update time
	bool is_in_gym = false;
	bool is_in_center = false;
	unsigned int stamina = 20;
	unsigned int experience_points = 0;
	double pokemon_dollars = 0;
	unsigned int training_units_to_buy = 0;
	unsigned int stamina_points_to_buy = 0;
	string name;
	PokemonCenter* current_center = NULL;
	PokemonGym* current_gym = NULL;
	Point2D destination;
	Vector2D delta; 

};

static double GetRandomAmountOfPokemonDollars();

#endif