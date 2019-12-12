/*Julia Zeng
EC 327 PA 4
Rival.cpp*/


#include "Rival.h"
#include "GameObject.h"
#include <string>

Rival::Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, 
	double def, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, 'R')
{
	this->name = name;
	speed = speed; 
	health = hp;
	physical_damage = phys_dmg;
	magical_damage = magic_dmg;
	defense = def;
}


void Rival::TakeHit(double physical_damage, double magical_damage, double defense)
{
	srand (time(NULL));
	int a = rand() % 2;
	double temp = 0; 
	if (a == 0)
		temp = physical_damage;
	else 
		temp = magical_damage;
	double damage = (100.0 - defense)/100 * temp;
	health -= damage; 
	cout << "Damage Inflicted : " << damage << endl;
	cout << this->GetName() << " Health: " << health << endl;
}

double Rival::get_phys_dmg()
{
	return physical_damage;
}
double Rival::get_magic_dmg()
{
	return magical_damage;
}
double Rival::get_defense()
{
	return defense;
}
double Rival::get_health()
{
	return health;
}

bool Rival::Update()
{
	if (health > 0)
	{
		state = ALIVE_RIVAL;
		return false;
	}
	else
	{
		state = FAINTED_RIVAL;
		return true;
	}
}

void Rival::ShowStatus()
{
	cout << name << " status: " ; GameObject::ShowStatus() ;
	if (state == ALIVE_RIVAL)
	{
		cout << " Alive" << endl;
	}
	else if (state == FAINTED_RIVAL)
	{
		cout << " Fainted" << endl;
	}
	else 
		cout << "Invalid rival state" << endl;
	cout << "	Health: " << health << endl;
	cout << "	Physical damage: " << physical_damage << endl;
	cout << "	Magical damage: " << magical_damage << endl;
	cout << "	Defense: " << defense << endl << endl;

}

bool Rival::IsAlive()
{
	if (health > 0) //rival is still alive
	{
		state = ALIVE_RIVAL;
		return true;
	}
	else 
	{
		state = FAINTED_RIVAL;
		return false;
	}
}

BattleArena* Rival::GetCurrentArenaPtr()
{
	return current_arena;
}


bool Rival::ShouldBeVisible()
{
	if (IsAlive())
		return true; 
	else
		return false;
}


string Rival::GetName()
{
	return name;
}