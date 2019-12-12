/*Julia Zeng
EC 327 PA 3
GameCommand.h*/

#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include <iostream>
#include "Pokemon.h"
#include "Model.h"
#include "Point2D.h"
#include "View.h"
#include "GameObject.h"
#include "Rival.h"
#include "BattleArena.h"



using namespace std;


void DoMoveCommand(Model &model, int pokemon_id, Point2D p1);
void DoMoveToCenterCommand(Model &model, int pokemon_id, int center_id);
void DoMoveToGymCommand(Model &model, int pokemon_id, int gym_id);
void DoStopCommand(Model &model, int pokemon_id);
void DoTrainInGymCommand(Model &model, int pokemon_id, unsigned int training_units);
void DoRecoverInCenterCommand(Model &model, int pokemon_id, unsigned int stamina_points);
void DoGoCommand(Model &model, View &view);
void DoRunCommand(Model &model, View &view);

//Include for PA4
void DoMoveToArenaCommand(Model &model, int pokemon_id, int arena_id); 
void DoStartBattleCommand(Model &model, int pokemon_id, int rival_id);
//



#endif