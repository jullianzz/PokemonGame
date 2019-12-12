/*Julia Zeng
EC 327 PA 3
Model.cpp*/

#include <iostream>
#include "Model.h"

using namespace std;

int NUM = 10;

Model::Model()  // default model constructor
{
	time = 0; 

	// pokemon_ptrs[0] = new Pokemon("Pikachu", 2, 20, 5, 4, 15, 1, Point2D(5,1));
	// pokemon_ptrs[1] = new Pokemon("Bulbasaur", 1, 20, 5, 4, 15, 2, Point2D(10,1));
	// center_ptrs[0] = new PokemonCenter(1, 1, 100, Point2D(1,20));
	// center_ptrs[1] = new PokemonCenter(2, 2, 200, Point2D(10,20));	
	// gym_ptrs[0] = new PokemonGym(10, 1, 2, 3, 1, Point2D(0,0));
	// gym_ptrs[1] = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5,5));


	// object_ptrs[0] = pokemon_ptrs[0];
	// object_ptrs[1] = pokemon_ptrs[1];
	// object_ptrs[2] = center_ptrs[0];
	// object_ptrs[3] = center_ptrs[1];
	// object_ptrs[4] = gym_ptrs[0]; 
	// object_ptrs[5] = gym_ptrs[1]; 


	// rival_ptrs[0] = new Rival("Charmander", 1, 20, 5, 4, 15, 1, OfficialBattleArena->GetLocation());
	// rival_ptrs[1] = new Rival("Squirtle", 2, 20, 5, 4, 15, 2, OfficialBattleArena->GetLocation()); 

	// object_ptrs[6] = rival_ptrs[0];
	// object_ptrs[7] = rival_ptrs[1];


	//Initialize GameObejct iterator

	Object_it = Object_ptrs.begin();
	center_it = PokemonCenter_ptrs.begin();
	gym_it = PokemonGym_ptrs.begin();
	pokemon_it = Pokemon_ptrs.begin();
	rival_it = Rival_ptrs.begin();
	arena_it = BattleArena_ptrs.begin();


	BattleArena* OfficialBattleArena1 = new BattleArena(3, 3, 4, 1, Point2D(15,12));
	BattleArena_ptrs.push_back(OfficialBattleArena1);

	Pokemon* Pikachu = new Pokemon("Pikachu", 2, 20, 5, 4, 15, 1, Point2D(5,1));
	Pokemon* Bulbasaur = new Pokemon("Bulbasaur", 1, 20, 5, 4, 15, 2, Point2D(10,1));
	PokemonCenter* PokemonCenter1 = new PokemonCenter(1, 1, 100, Point2D(1,20));
	PokemonCenter* PokemonCenter2 = new PokemonCenter(2, 2, 200, Point2D(10,20));
	PokemonGym* PokemonGym1 = new PokemonGym(10, 1, 2, 3, 1, Point2D(0,0));
	PokemonGym* PokemonGym2 = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5,5));
	Rival* Rival1 = new Rival("Charmander", 1, 20, 5, 4, 15, 1, OfficialBattleArena1->GetLocation()); 
	Rival* Rival2 = new Rival("Squirtle", 2, 20, 5, 4, 15, 2, OfficialBattleArena1->GetLocation());
	Rival* Rival3 = new Rival("Psyduck", 2, 20, 5, 4, 15, 3, OfficialBattleArena1->GetLocation());

	Pokemon_ptrs.push_back(Pikachu);
	Pokemon_ptrs.push_back(Bulbasaur);
	PokemonCenter_ptrs.push_back(PokemonCenter1);
	PokemonCenter_ptrs.push_back(PokemonCenter2);
	PokemonGym_ptrs.push_back(PokemonGym1);
	PokemonGym_ptrs.push_back(PokemonGym2);
	Rival_ptrs.push_back(Rival1);
	Rival_ptrs.push_back(Rival2);


	Object_ptrs.push_back(Pikachu);
	Object_ptrs.push_back(Bulbasaur);
	Object_ptrs.push_back(PokemonCenter1);
	Object_ptrs.push_back(PokemonCenter2);
	Object_ptrs.push_back(PokemonGym1);
	Object_ptrs.push_back(PokemonGym2);
	Object_ptrs.push_back(Rival1);
	Object_ptrs.push_back(Rival2);
	Object_ptrs.push_back(Rival3);
	Object_ptrs.push_back(OfficialBattleArena1);


	Active_ptrs.push_back(Pikachu);
	Active_ptrs.push_back(Bulbasaur);
	Active_ptrs.push_back(PokemonCenter1);
	Active_ptrs.push_back(PokemonCenter2);
	Active_ptrs.push_back(PokemonGym1);
	Active_ptrs.push_back(PokemonGym2);
	Active_ptrs.push_back(Rival1);
	Active_ptrs.push_back(Rival2);
	Active_ptrs.push_back(Rival3);
	Active_ptrs.push_back(OfficialBattleArena1);


//


	cout << "Model default constructed" << endl;
}

// Model::~Model()
// {
// 	for (int i = 0; i < NUM; i++)
// 	{
// 		delete pokemon_ptrs[i];
// 	}
// 	for (int i = 0; i < NUM; i++)
// 	{
// 		delete object_ptrs[i];
// 	}
// }


Model::~Model()
{
	for (pokemon_it = Pokemon_ptrs.begin(); pokemon_it != Pokemon_ptrs.end(); pokemon_it++)
	{
		delete *pokemon_it;
	}
	for (Object_it = Object_ptrs.begin(); Object_it != Object_ptrs.end();  Object_it++)
	{
		delete *Object_it;
	}
}


Pokemon* Model::GetPokemonPtr(int id)
{
	for (pokemon_it = Pokemon_ptrs.begin(); pokemon_it != Pokemon_ptrs.end(); pokemon_it++)
	{
		if ((*pokemon_it)->GetId() == id)
			return *pokemon_it; 
	}
	return 0; // No pointer match
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
	for (center_it = PokemonCenter_ptrs.begin(); center_it != PokemonCenter_ptrs.end(); center_it++)
	{
		if ((*center_it)->GetId() == id)
			return *center_it; 
	}
	return 0; // No pointer match

}

// PokemonGym* Model::GetPokemonGymPtr(int id)
// {
// 	for (int i = 0; i < num_gyms; i++)
// 	{
// 		if ((*gym_ptrs[i]).GetId() == id)
// 			return gym_ptrs[i]; 
// 	}
// 	return 0; // No pointer match
// }

PokemonGym* Model::GetPokemonGymPtr(int id)
{
	for (gym_it = PokemonGym_ptrs.begin(); gym_it != PokemonGym_ptrs.end(); gym_it++)
	{
		if ((*gym_it)->GetId() == id)
			return *gym_it; 
	}
	return 0; // No pointer match
}


//Include for PA4
// Rival* Model::GetRivalPtr(int id)
// {
// 	for (int i = 0; i < num_rivals; i++)
// 	{
// 		if (rival_ptrs[i]->GetId() == id)
// 			return rival_ptrs[i];
// 	}
// 	return 0;
// }

Rival* Model::GetRivalPtr(int id)
{
	for (rival_it = Rival_ptrs.begin(); rival_it != Rival_ptrs.end(); rival_it++)
	{
		if ((*rival_it)->GetId() == id)
			return *rival_it;
	}
	return 0;
}

BattleArena* Model::GetBattleArenaPtr(int id)
{
	for (arena_it = BattleArena_ptrs.begin(); arena_it != BattleArena_ptrs.end(); arena_it++)
	{
		if ((*arena_it)->GetId() == id)
			return *arena_it;
	}
	return 0;
}


//


bool Model::Update()
{
	time ++;
	bool temp = false;
	bool allBeaten = true;
	bool allExhausted = true;


	for (active_it = Active_ptrs.begin(); active_it != Active_ptrs.end(); active_it++)
	{
		// cout << "UPDATING \n\n\n" << endl;
		if ((*active_it)->Update())
		{
			//cout << (*object_ptrs[i]).GetDisplayCode() << (*object_ptrs[i]).GetId() << endl;
			temp = true; 
		}

		// if (OfficialBattleArena->Update())
		// 	temp = true;
	}


	// Deleting dead objects
	for (active_it = Active_ptrs.begin(); active_it != Active_ptrs.end(); active_it++) 
	{
		if ((*active_it)->ShouldBeVisible() == false)
		{
			active_it = Active_ptrs.erase(active_it);
			cout << "Dead object removed" << endl;
		}
	}

	cout << "Size of active ptrs is " << Active_ptrs.size() << endl;


	for (center_it = PokemonCenter_ptrs.begin(); center_it != PokemonCenter_ptrs.end(); center_it++)
	{
		if ((*center_it)->GetState() == NOT_BEATEN)
			allBeaten = false; 

	}
	
	for (pokemon_it = Pokemon_ptrs.begin(); pokemon_it != Pokemon_ptrs.end(); pokemon_it++)
	{
		if (!(*pokemon_it)->IsExhausted())
			allExhausted = false;
	}

	if (allBeaten)
	{
		cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
		// exit through exit function
		exit(0); 
	}

	else if (allExhausted)
	{
		cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
		//exit using exit function
		exit(0);
	}

	return temp;
}

void Model::Display(View& view)
{
	cout << "Time: " << time << endl;
	view.Clear();
	for (active_it = Active_ptrs.begin(); active_it != Active_ptrs.end(); active_it++)
	{
		//object_ptrs[i]->location;
		view.Plot(*active_it);
	}

	view.Draw();
}

void Model::ShowStatus()
{
	for (Object_it = Object_ptrs.begin(); Object_it != Object_ptrs.end(); Object_it++)
	{
		(*Object_it)->ShowStatus();
	}

}

int Model::GetTime()
{
	return time;
}


void Model::NewCommand(char type, int ID1, int x, int y)
{
	if (type == 'g')
	{
		try{
			if (GetPokemonGymPtr(ID1) != 0)
			{
				throw Invalid_Input("PokemonGym pointer already exists") ;
			}
			PokemonGym* new_PokemonGym = new PokemonGym(20, 5, 7, 8, ID1, Point2D(x,y));
			PokemonGym_ptrs.push_back(new_PokemonGym);
			Object_ptrs.push_back(new_PokemonGym);
			Active_ptrs.push_back(new_PokemonGym);

		}
		catch (Invalid_Input& except)
		{
			cout << "Invalid input - " << except.msg_ptr << endl;
		}
	}
	else if (type == 'c')
	{
		try{
			if (GetPokemonCenterPtr(ID1) != 0)
			{
				throw Invalid_Input("PokemonCenter pointer already exists") ;
			}
			PokemonCenter* new_PokemonCenter = new PokemonCenter(ID1, 1, 200, Point2D(x,y));
			PokemonCenter_ptrs.push_back(new_PokemonCenter);
			Object_ptrs.push_back(new_PokemonCenter);
			Active_ptrs.push_back(new_PokemonCenter);
		}
		catch (Invalid_Input& except)
		{
			cout << "Invalid input - " << except.msg_ptr << endl;
		}
	}
	else if (type == 'p')
	{
		try{
			if (GetPokemonPtr(ID1) != 0)
			{
				throw Invalid_Input("Pokemon pointer already exists") ;
			}
			string in_name;
			cout << "Enter the name for your new Pokemon" << endl;
			cin >> in_name;
			Pokemon* new_Pokemon = new Pokemon(in_name, 2, 20, 5, 4, 15, ID1, Point2D(x,y)); 
			Pokemon_ptrs.push_back(new_Pokemon);
			Object_ptrs.push_back(new_Pokemon);
			Active_ptrs.push_back(new_Pokemon);
		}
		catch (Invalid_Input& except)
		{
			cout << "Invalid input - " << except.msg_ptr << endl;
		}
		
	}
	else  //type if 'r' rival
	{
		try{
			if (GetRivalPtr(ID1) != 0)
			{
				throw Invalid_Input("Rival pointer already exists") ;
			}
			string in_name;
			cout << "Enter the name for your new Rival" << endl;
			cin >> in_name;
			arena_it = BattleArena_ptrs.begin();
			Rival* new_Rival = new Rival(in_name, 2, 20, 5, 4, 15, ID1, (*arena_it)->GetLocation()); 
			Rival_ptrs.push_back(new_Rival);
			Object_ptrs.push_back(new_Rival);
			Active_ptrs.push_back(new_Rival);
		}
		catch (Invalid_Input& except)
		{
			cout << "Invalid input - " << except.msg_ptr << endl;
		}
	
	}
	
}

// bool Model::Update()
// {
// 	time ++;
// 	bool temp = false;
// 	bool allBeaten = true;
// 	bool allExhausted = true;

// 	for (int i = 0; Object_it != NULL; i++)
// 	{
// 		// cout << "UPDATING \n\n\n" << endl;
// 		Object_it = Object_ptrs.begin();
// 		advance(Object_it, i);
// 		if ((*Object_it).Update())
// 		{
// 			//cout << (*object_ptrs[i]).GetDisplayCode() << (*object_ptrs[i]).GetId() << endl;
// 			temp = true; 
// 		}

// 		if (OfficialBattleArena->Update())
// 			temp = true;
// 	}


// 	for (int i = 0; center_it != NULL; i++)
// 	{
// 		center_it = PokemonCenter_ptrs.begin();
// 		advance(center_it, i);
// 		if ((*center_it).GetState() == NOT_BEATEN)
// 			allBeaten = false; 

// 	}

// 	for (int i = 0; i < num_pokemon; i++)
// 	{
// 		if (!(*pokemon_ptrs[i]).IsExhausted())
// 			allExhausted = false;
// 	}

// 	if (allBeaten)
// 	{
// 		cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
// 		// exit through exit function
// 		exit(0); 
// 	}
// 	else if (allExhausted)
// 	{
// 		cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
// 		//exit using exit function
// 		exit(0);
// 	}

// 	return temp;
// }

// void Model::Display(View& view)
// {
// 	cout << "Time: " << time << endl;
// 	view.Clear();
// 	for (int i = 0; i < num_objects; i++)
// 	{
// 		//object_ptrs[i]->location;
// 		view.Plot(object_ptrs[i]);
// 	}

// 	view.Draw();
// }

// void Model::ShowStatus()
// {
// 	for (int i = 0; i < num_objects; i++)
// 	{
// 		object_ptrs[i]->ShowStatus();
// 	}

// 	OfficialBattleArena->ShowStatus();
// }

// int Model::GetTime()
// {
// 	return time;
// }



