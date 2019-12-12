/*Julia Zeng
EC 327 PA 3
GameCommand.cpp*/

#include <iostream>
#include "GameCommand.h"


using namespace std;


void DoMoveCommand(Model &model, int pokemon_id, Point2D p1)
{
	cout << "Time: " << model.GetTime() << endl;
	Pokemon* pokemon1ptr = model.GetPokemonPtr(pokemon_id); 
	cout << "Moving " << pokemon1ptr->GetName() << " to " << p1 << endl;
	pokemon1ptr->StartMoving(p1);
	model.ShowStatus();
}

void DoMoveToCenterCommand(Model &model, int pokemon_id, int center_id)
{
	cout << "Time: " << model.GetTime() << endl;
	Pokemon* pokemon1ptr = model.GetPokemonPtr(pokemon_id);
	PokemonCenter* pokemoncenterptr = model.GetPokemonCenterPtr(center_id);
	cout << "Moving " << pokemon1ptr->GetName() << " to center" << center_id << endl;
	pokemon1ptr->StartMovingToCenter(pokemoncenterptr);
	model.ShowStatus();
}

void DoMoveToGymCommand(Model &model, int pokemon_id, int gym_id)
{

	cout << "Time: " << model.GetTime() << endl;
	Pokemon* pokemon1ptr = model.GetPokemonPtr(pokemon_id);
	//cout << "Moving " << pokemon1ptr->GetName() << "to gym " << gym_id << endl;
	PokemonGym* pokemongymptr = model.GetPokemonGymPtr(gym_id);
	cout << "Moving " << pokemon1ptr->GetName() << " to gym " << gym_id << endl;
	pokemon1ptr->StartMovingToGym(pokemongymptr);
	model.ShowStatus();
}

void DoStopCommand(Model &model, int pokemon_id)
{

	cout << "Time: " << model.GetTime() << endl;
	Pokemon* pokemon1ptr = model.GetPokemonPtr(pokemon_id);
	cout << "Stopping " << pokemon1ptr->GetName() << endl;
	pokemon1ptr->Stop();
	model.ShowStatus();
}

void DoTrainInGymCommand(Model &model, int pokemon_id, unsigned int training_units)
{	

	cout << "Time: " << model.GetTime() << endl;
	Pokemon* pokemon1ptr = model.GetPokemonPtr(pokemon_id);
	cout << "Training " << pokemon1ptr->GetName() << endl;
	pokemon1ptr->StartTraining(training_units);
	model.ShowStatus();
}

void DoRecoverInCenterCommand(Model &model, int pokemon_id, unsigned int stamina_points)
{

	cout << "Time: " << model.GetTime() << endl;
	Pokemon* pokemon1ptr = model.GetPokemonPtr(pokemon_id);
	cout << "Recovering " << pokemon1ptr->GetName() << "'s stamina" << endl;
	pokemon1ptr->StartRecoveringStamina(stamina_points);
	model.ShowStatus();
}

void DoGoCommand(Model &model, View &view)
{
	cout << "Advancing one tick" << endl;
	model.Update();
	model.ShowStatus();
	model.Display(view);
}

void DoRunCommand(Model &model, View &view)
{
	//view.Clear();
	bool perform = true;
	for (int i = 1; i <= 5; i++)
	{
		cout << "Advancing next event " << i << endl;

		if (model.Update())
		{
			perform = true; 
			break;
		}
		model.ShowStatus();

	}
	if (perform)
		model.ShowStatus();

	model.Display(view);
}


void DoMoveToArenaCommand(Model &model, int pokemon_id, int arena_id)
{
	cout << "Time: " << model.GetTime() << endl;
	Pokemon* pokemon1ptr = model.GetPokemonPtr(pokemon_id);
	BattleArena* arenaptr = model.GetBattleArenaPtr(arena_id);
	cout << "Moving " << pokemon1ptr->GetName() << " to battle arena " << arenaptr->GetId() << endl;
	pokemon1ptr->StartMovingToArena(arenaptr);
	model.ShowStatus();
	//cout << "IT LIVES!" << endl;
}

void DoStartBattleCommand(Model &model, int pokemon_id, int rival_id)
{
	cout << "Time: " << model.GetTime() << endl;
	Pokemon* pokemon1ptr = model.GetPokemonPtr(pokemon_id);
	pokemon1ptr->SetTarget(model.GetRivalPtr(rival_id)) ;
	cout << "Starting battle between " << pokemon1ptr->GetName() << " and " << pokemon1ptr->GetTarget()->GetName() << endl;
	pokemon1ptr->StartBattle();
	model.ShowStatus();
}


