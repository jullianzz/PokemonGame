/*Julia Zeng
EC 327 PA 3
Pokemon.cpp*/

#include <iostream>
#include "Pokemon.h"
using namespace std;


static double GetRandomAmountOfPokemonDollars()		//function returns random double between 0 and 2
{
	srand(time(NULL));
	double u = double(rand()%10000)/10000.0 * 2.0; 
	return u;
}

Pokemon::Pokemon() : GameObject('P')
{
	speed = 5;
	state = STOPPED;
	cout << "Pokemon default constructed" << endl;
}

Pokemon::Pokemon(char in_code) : GameObject(in_code)
{
	speed = 5;
	state = STOPPED;
	display_code = in_code;
	cout << "Pokemon constructed" << endl;
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) 
	: GameObject(in_loc, in_id, in_code)
{
	state = STOPPED;
	speed = in_speed;
	name = in_name;
	cout << "Pokemon constructed" << endl;
}

Pokemon::Pokemon(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, Point2D in_loc)
	: GameObject(in_loc, in_id, 'P')
{
	name = in_name;
	this->speed = speed; 
	health = hp; 
	physical_damage = phys_dmg; 
	magical_damage = magic_dmg;
	defense = def; 
} 


bool Pokemon::IsExhausted()
{
	if (stamina <= 0 || health <= 0)
		return true;
	else 
		return false;
}

void Pokemon::StartMoving(Point2D dest)
{
	SetupDestination(dest);
	state = MOVING;
	if (location.x == dest.x && location.y == dest.y)
		cout << display_code << id_num << ": I'm already there. See?" << endl;
	else if (IsExhausted())
		cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me." << endl;
	else 
		cout << display_code << id_num << ": On my way." << endl;
}

void Pokemon::StartMovingToCenter(PokemonCenter* center)
{
	current_center = center;  //current_center now points to current_center
	Point2D dest = (*center).GetLocation();
	SetupDestination(dest);
	state = MOVING_TO_CENTER;
	if (location.x == dest.x && location.y == dest.y)
		cout << display_code << id_num << ": I am already at the Pokemon Center!" << endl;
	else if (IsExhausted())
		cout << display_code << id_num << ": I am exhausted so I can't move to recover stamina. . ." << endl;
	
	else cout << display_code << id_num << ": on my way to center " << center->GetId() << endl;
}

void Pokemon::StartMovingToGym(PokemonGym* gym)
{
	current_gym = gym;
	Point2D dest = (*gym).GetLocation();
	SetupDestination(dest);
	state = MOVING_TO_GYM;
	if (location.x == dest.x && location.y == dest.y)
		cout << display_code << id_num << ": I am already at the Pokemon Gym!" << endl;
	else if (IsExhausted())
		cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the gym. . ." << endl;
	else cout << display_code << id_num << ": on my way to gym " << gym->GetId() << endl;
}

void Pokemon::StartTraining(unsigned int num_training_units)
{
	if (!is_in_gym)
		cout << display_code << id_num << ": I can only train in a Pokemon Gym!" << endl;
	else if (IsExhausted())
		cout << display_code << id_num << ": I am exhausted so no more training for me. . ." << endl;
	else if (stamina < (*current_gym).GetStaminaCost(num_training_units) || pokemon_dollars < (*current_gym).GetDollarCost(num_training_units))
		cout << display_code << id_num << ": Not enough stamina and/or money for training" << endl;
	else if ((*current_gym).GetState() == BEATEN)
		cout << display_code << id_num << ": Cannot train! This Pokemon Gym is already beaten!" << endl;
	else 
	{
		state = TRAINING_IN_GYM;
		cout << display_code << id_num << ": Started to train at Pokemon Gym " << (*current_gym).GetId() << " with " <<
			num_training_units << " training units" << endl;
		if (num_training_units <= (*current_gym).GetNumTrainingUnitsRemaining())
			training_units_to_buy = num_training_units;
		else 
			training_units_to_buy = (*current_gym).GetNumTrainingUnitsRemaining(); 
	}
}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
	state = RECOVERING_STAMINA; 
	if (!is_in_center)
		cout << display_code << id_num << ": I can only recover stamina at a Pokemon Center!" << endl;
	else if (pokemon_dollars < (*current_center).GetDollarCost(num_stamina_points))
		cout << display_code << id_num << ": Not enough money to recover stamina." << endl;
	else if (!(*current_center).HasStaminaPoints())
		cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center" << endl;
	else 
	{
		cout << display_code << id_num << ": Started recovering " << num_stamina_points << " stamina point(s) at Pokemon Center " <<
			(*current_center).GetId() << endl; 
		if (num_stamina_points <= (*current_center).GetNumStaminaPointsRemaining())
			stamina_points_to_buy = num_stamina_points;
		else 
			stamina_points_to_buy = (*current_center).GetNumStaminaPointsRemaining();
	}
}

void Pokemon::SetupDestination(Point2D dest)
{
	destination.x = dest.x;
	destination.y = dest.y;
	Vector2D m(dest-location);
	delta = m * (speed / GetDistanceBetween(dest, location));
}


bool Pokemon::Update()
{
	switch (state)
	{
		case STOPPED:
		{ 
			return false; 
			break;
		}
		case MOVING:
		{
			bool tempCenter = is_in_center;
			bool tempGym = is_in_gym;
			if (UpdateLocation())
			{
				state = STOPPED;
				if (tempCenter == true)
				{
					(*current_center).RemoveOnePokemon();
					is_in_center = false;
				}
				else if (tempGym == true)
				{
					(*current_gym).RemoveOnePokemon();
				}
				return true;
			}
			else 
			{
				if (tempCenter == true)
				{
					(*current_center).RemoveOnePokemon();
					is_in_center = false;
				}
				else if (tempGym == true)
				{
					(*current_gym).RemoveOnePokemon();
				}
				return false;
			}

			break;
		}
		case MOVING_TO_CENTER: 
		{
			if (UpdateLocation())
			{
				bool tempGym = is_in_gym;
				if (tempGym == true)
				{
					(*current_gym).RemoveOnePokemon();
				}
				state = IN_CENTER;
				is_in_center = true;
				(*current_center).AddOnePokemon();
				return true;
			}
			else 
			{
				return false;
			}

			break;
		}
		case MOVING_TO_GYM:
		{
			if (UpdateLocation())
			{
				bool tempCenter = is_in_center;
				if (tempCenter == true)
				{
					(*current_center).RemoveOnePokemon();
				}

				state = IN_GYM;
				is_in_gym = true;
				(*current_gym).AddOnePokemon();
				return true;
			}
			else
			{
				return false;
			}
		}
		case IN_CENTER:
		{
			return false;
			break;
		}
		case IN_GYM:
		{
			return false;
			break;
		}
		case TRAINING_IN_GYM:
		{
			unsigned int reduceStaminaAmtBy = (*current_gym).GetStaminaCost(training_units_to_buy) ;
			stamina -= reduceStaminaAmtBy;
			unsigned int reducePokeDollarsBy = (*current_gym).GetDollarCost(training_units_to_buy);
			pokemon_dollars -= reducePokeDollarsBy;
			unsigned int experience_points_gained = (*current_gym).TrainPokemon(training_units_to_buy);
			experience_points += experience_points_gained;
			cout << "** " << name << " completed " << training_units_to_buy << " training unit(s)! **" << endl;
			cout << "** " << name << " gained " << experience_points_gained << " experience point(s)! **" << endl;
			state = IN_GYM;
			return true;	
		}
		case RECOVERING_STAMINA:
		{
			unsigned int stamina_gained = (*current_center).DistributeStamina(stamina_points_to_buy);
			stamina += stamina_gained;
			pokemon_dollars -= (*current_center).GetDollarCost(stamina_gained);
			cout << "** " << name << " recovered " << stamina_gained << " stamina point(s)! **" << endl;
			state = IN_CENTER;
			return true;
		}
		case FAINTED:
		{
			state = FAINTED;
			return false; 
		}
		case MOVING_TO_ARENA:
		{
			if (UpdateLocation())
			{
				//cout << "WOOHOO" << endl;
				state = IN_ARENA;
				is_in_arena = true;
				current_arena->AddOnePokemon();
				//cout << "Poke count is " << current_arena->GetPokemonCount() << endl;
				return true;
			}
			else
			{
				return false;
			}
		}
		case BATTLE:
		{
			stamina -= current_arena->GetStaminaCost();
			pokemon_dollars -= current_arena->GetDollarCost();
			if (StartBattle())
			{
				cout << "Congrats! You defeated one rival!" << endl;
				health = 20;
				state = IN_ARENA;
				target->IsAlive();
				current_arena->RemoveOneRival();
				return true; 
			}
			else 
			{
				cout << "Oh no! Pokemon has fainted" << endl;
				state = FAINTED;
				target->IsAlive();
				return true; 
			}
		}
		default:
		{
			cout << "Invalid state; default switch invoked" << endl;
			return false;
			break;
		}
	}

}

bool Pokemon::UpdateLocation()
{
	if (location.x == destination.x && location.y == destination.y)
	{
		cout << display_code << id_num << ": I'm there!" << endl;
		return true;
	}
	
	else if (IsExhausted())
	{
		cout << name << " is exhausted and has no more stamina! Cannot move." << endl;
		state = STOPPED;
		return false;
	}

	else if ( (fabs((destination - location).x) <= fabs(delta.x)) && (fabs((destination - location).y) <= fabs(delta.y)) )
	{
		location.x = destination.x;
		location.y =  destination.y;
		cout << display_code << id_num << ": I'm there!" << endl;
		// cout << "current_arena pokemon is " << current_arena->pokemon_count << endl;
		stamina -= 1;
		pokemon_dollars += GetRandomAmountOfPokemonDollars();
		return true;
	}
	else
	{
		cout << display_code << id_num << ": step. . ." << endl;
		location = location + delta;
		stamina -= 1;
		pokemon_dollars += GetRandomAmountOfPokemonDollars();
		return false;
	}
}


void Pokemon::ShowStatus()
{
	cout << name << " status: " ; GameObject::ShowStatus() ;
		// cout << "fjsjd pokemon count is " << current_arena->pokemon_count << endl;
	if (state == STOPPED)
		cout << " stopped" << endl ;
	else if (state == MOVING)
		cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << endl;
	else if (state == MOVING_TO_CENTER)
		cout << " heading to Pokemon Center " << (*current_center).GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
	else if (state == IN_CENTER)
		cout << " inside Pokemon Center " << (*current_center).GetId() << endl;
	else if (state == MOVING_TO_GYM)
		cout << " heading to Pokemon Gym " << (*current_gym).GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
	else if (state == IN_GYM)
		cout << " inside Pokemon Gym" << (*current_gym).GetId() << endl;
	else if (state == TRAINING_IN_GYM)
		cout << " training in Pokemon Gym " << (*current_gym).GetId() << endl;
	else if (state == RECOVERING_STAMINA)
		cout << " recovering stamina in Pokemon Center " << (*current_center).GetId() << endl;

	else if (state == EXHAUSTED)
		cout << " is exhausted" << endl;
	else if (state == IN_ARENA)
		cout << " inside Battle Arena " << (*current_arena).GetId() << endl;
	else if (state == MOVING_TO_ARENA)
		cout << " is moving to Battle Arena " << (*current_arena).GetId() << endl;
	else if (state == BATTLE)
		cout << " about to battle " << target->GetName() << endl;
	else if (state == FAINTED)
		cout << " has FAINTED! Cannot be revived. " << endl;


	else
	{

	}
	// cout << "Arena count " << current_arena->GetPokemonCount()<< endl;
	cout << "	Stamina: " << stamina << endl;
	cout << "	Pokemon Dollars: " << pokemon_dollars << endl;
	cout << "	Experience Points: " << experience_points << endl;
	cout << "	Health: " << health << endl;
	cout << "	Physical damage: " << physical_damage << endl;
	cout << "	Magical damage: " << magical_damage << endl;
	cout << "	Defense: " << defense << endl << endl;
}

void Pokemon::Stop()
{
	state = STOPPED;
	cout << display_code << id_num << ": Stopping. . . " << endl;
}

bool Pokemon::ShouldBeVisible()
{
	if (!IsExhausted() && state != FAINTED)
		return true;
	else 
		return false;            
}

Pokemon::~Pokemon()
{
	cout << "Pokemon destructed" << endl;
}

string Pokemon::GetName()
{
	return name;
}


//Include for PA4

bool Pokemon::isAlive()
{
	if (state != FAINTED)
		return true;
	else if (state == FAINTED)
		return false;
	else 
	{
		cout << "Invlaid state!" << endl;
		return true;
	}

}


void Pokemon::TakeHit(double physical_damage, double magical_damage, double defense)
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
	cout << "Damage Inflicted: " << damage << endl;
	cout << this->GetName() << " Health: " << health << endl;
}

void Pokemon::ReadyBattle(Rival* in_target)
{
	if (state == IN_ARENA && current_arena->IsAbleToFight(pokemon_dollars, stamina) 
		&& current_arena->IsBeaten() == false && in_target->IsAlive())
	{
		target = in_target;
		state =  BATTLE;
	}
	else
		state = IN_ARENA;
}

bool Pokemon::StartBattle()
{
	if (!is_in_arena)
	{
		cout << display_code << id_num << ": I can only start battle in a battle arena!" << endl;
		return false;
	}
	else if (state == BATTLE)
	{
		while(target->get_health() > 0 && health > 0)
		{
			cout << target->GetName() << "'s turn: " << endl;
			this->TakeHit(5,4,15);  //rival attacks first and pokemon takes a hit
			if (health <= 0)
			{
				cout << endl;
				return false; //pokemon fainted 
			}
			cout << this->GetName() << "'s turn: " << endl;
			target->TakeHit(5,4,15);
			if (target->get_health() <= 0)
			{
				cout << endl;
				return true; //pokemon won battle
			}
			cout << "**************\n" << endl;
			
		}
		return false;
	}
	else 
	{
		state = BATTLE;
	}
	return false;
}


void Pokemon::StartMovingToArena(BattleArena* arena)
{
	state = MOVING_TO_ARENA; 
	current_arena = arena;
	// cout << "sknf " << current_arena->GetPokemonCount() << endl;
	Point2D dest = (*arena).GetLocation();
	SetupDestination(dest);
	if (location.x == dest.x && location.y == dest.y)
		cout << display_code << id_num << ": I am already at the Pokemon Arena!" << endl;
	else if (IsExhausted())
		cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the arena. . ." << endl;
	else cout << display_code << id_num << ": on my way to arena " << arena->GetId() << endl;
}

void Pokemon::SetTarget(Rival* rival_ptr)
{
	target = rival_ptr; 
}

Rival* Pokemon::GetTarget()
{
	return target;
}

//






