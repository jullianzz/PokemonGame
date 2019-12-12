/*Julia Zeng
EC 327 PA 3
main.cpp*/

#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
#include "Vector2D.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "View.h"
#include "GameCommand.h"
#include "Input_Handling.h"

using namespace std;

int main()
{
	cout << R"(
	                                  ,'\
	    _.----.        ____         ,'  _\   ___    ___     ____
	_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
	\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
	 \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
	   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
	    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
	     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
	      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
	       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
	        \_.-'       |__|    `-._ |              '-.|     '-.| |   |
	                                `'                            '-._|
	                                )"
	            << '\n';

	View view;
	Model model; 
	//cout << "Battle arena id is " << model.OfficialBattleArena->GetId() << endl;

	char command;

	view.Clear();

	model.Display(view);

	while(true)
	{
		cout << "\n\n\n\n\t\t\tNEXT PLAY\n\n\n\n " ;

		cout << "Enter a command. The viable options are: " << endl;
		cout << "\tMove('m')" << endl;
		cout << "\tMove towards a Pokemon Gym('g')" << endl;
		cout << "\tMove towards a Pokemon Center('c')" << endl;
		cout << "\tStop('s')" << endl;
		cout << "\tRecover at a Pokemon Center('r')" << endl;
		cout << "\tComplete training units at Pokemon Gym('t')" << endl;
		cout << "\tGo: This advances one time step('v')" << endl;
		cout << "\tRun: This advances one time step continuously('x')" << endl;
		cout << "\tBattle: This starts battle between pokemon and rival('b')" << endl;
		cout << "\tMove to Arena: This moves pokemon into the arena('a')" << endl;
		cout << "\tCreate a new object('n')" << endl;
		cout << "\tQuit('q')" << endl;

		cin >> command; 


		if (command =='q')
		{
			exit(0); 
		}
		

		int ID1, ID2, x, y, training_unit_amt, stamina_unit_amt;
		char type; 

		
		cout << endl;

		try 
		{
			switch (command)
			{
				case 'm':
				{
					cout << "Pokemon ID, x-coordinate, y-coordinate" << endl;
					cin >> ID1 >> x >> y ;
					try {
						if (model.GetPokemonPtr(ID1) == 0)
						{
							throw Invalid_Input("Was expecting a valid ID");
						}
						DoMoveCommand(model, ID1, Point2D(x,y));
					}
					catch (Invalid_Input& except)
					{
						cout << "Invalid input - " << except.msg_ptr << endl;
					}
					break;
				}
				case 'g':
				{
					cout << "Pokemon ID, Pokemon Gym ID" << endl;
					cin >> ID1 >> ID2 ;
					try {
						if (model.GetPokemonPtr(ID1) == 0 && model.GetPokemonGymPtr(ID2) == 0)
						{
							throw Invalid_Input("Was expecting a valid ID");
						}
						DoMoveToGymCommand(model, ID1, ID2);
					}
					catch (Invalid_Input& except)
					{
						cout << "Invalid input - " << except.msg_ptr << endl;
					}

					break;
				}
				case 'c':
				{
					cout << "Pokemon ID, Pokemon Center ID" << endl;
					cin >> ID1 >> ID2;
					try {
						if (model.GetPokemonPtr(ID1) == 0 && model.GetPokemonCenterPtr(ID2) == 0)
						{
							throw Invalid_Input("Was expecting a valid ID");
						}
						DoMoveToCenterCommand(model, ID1, ID2);
					}
					catch (Invalid_Input& except)
					{
						cout << "Invalid input - " << except.msg_ptr << endl;
					}
					break;
				}
				case 's':
				{
					cout << "Pokemon ID" << endl;
					cin >> ID1 ;
					try {
						if (model.GetPokemonPtr(ID1) == 0)
						{
							throw Invalid_Input("Was expecting a valid ID");
						}
						DoStopCommand(model, ID1);
					}
					catch (Invalid_Input& except)
					{
						cout << "Invalid input - " << except.msg_ptr << endl;
					}
					break;
				}
				case 't':
				{
					cout << "Pokemon ID, Pokemon Gym ID, Amount of Training Units" << endl;
					cin >> ID1 >> ID2 >> training_unit_amt ;
					try {
						if (model.GetPokemonPtr(ID1) == 0 && model.GetPokemonGymPtr(ID2) == 0)
						{
							throw Invalid_Input("Was expecting a valid ID");
						}
						DoTrainInGymCommand(model, ID1, training_unit_amt);
					}
					catch (Invalid_Input& except)
					{
						cout << "Invalid input - " << except.msg_ptr << endl;
					}
					break;
				}
				case 'v': // Go
				{ 
					cout << "No user-input required..." << endl;
					DoGoCommand(model, view);
					break;
				}
				case 'x':
				{
					cout << "No user-input required..." << endl;
					DoRunCommand(model, view);
					break;
				}
				case 'r':
				{
					cout << "Pokemon ID, Pokemon Center ID, Amount of Stamina Units" << endl;
					cin >> ID1 >> ID2 >> stamina_unit_amt; 
					try {
						if (model.GetPokemonPtr(ID1) == 0 && model.GetPokemonCenterPtr(ID2) == 0)
						{
							throw Invalid_Input("Was expecting a valid ID");
						}
						DoRecoverInCenterCommand(model, ID1, stamina_unit_amt);
					}
					catch (Invalid_Input& except)
					{
						cout << "Invalid input - " << except.msg_ptr << endl;
					}
					break;
				}
				case 'b':
				{
					cout << "Pokemon ID, Rival ID" << endl;
					cin >> ID1 >> ID2 ;
					try {
						if (model.GetPokemonPtr(ID1) == 0 && model.GetRivalPtr(ID2) == 0)
						{
							throw Invalid_Input("Was expecting a valid ID");
						}
						DoStartBattleCommand(model, ID1, ID2);
					}
					catch (Invalid_Input& except)
					{
						cout << "Invalid input - " << except.msg_ptr << endl;
					}
					break;
				}
				case 'a': //move pokemon to arena
				{
					cout << "Pokemon ID, Arena ID" << endl;
					cin >> ID1 >> ID2 ;
					try {
						if (model.GetPokemonPtr(ID1) == 0 && model.GetBattleArenaPtr(ID2) == 0)
						{
							throw Invalid_Input("Was expecting a valid ID");
						}
						DoMoveToArenaCommand(model, ID1, ID2); 
					}
					catch (Invalid_Input& except)
					{
						cout << "Invalid input - " << except.msg_ptr << endl;
					}
					break;

				}
				case 'n':
				{
					cout << "Possible GameObject types to create are PokemonGym(g), PokemonCenter(c), Pokemon(p), and Rival(r)" << endl;
					cout << "Object Type, ID, X, Y" << endl;
					cin >> type >> ID1 >> x >> y ;
					try {
						if (type != 'g' && type != 'c' && type != 'p' && type != 'r')
						{
							throw Invalid_Input("Was expecting a valid GameObject type");
						}
						if (ID1 != (int)ID1)
						{
							throw Invalid_Input("Was expecting a valid ID") ;
						}
						if (x != (int)x || y != (int)y)
						{
							throw Invalid_Input("Was expecting valid coordinates");
						}
						model.NewCommand(type, ID1, x, y);
					}
					catch (Invalid_Input& except)
					{
						cout << "Invalid input - " << except.msg_ptr << endl;
					}
					break;
				}
				default:
				{

					//cout << "The default was prompted, something's up" << endl;
					throw Invalid_Input("Was expecting a command code listed");
					break;
				}
			}
		}
		catch (Invalid_Input& except)
		{
			cout << "Invalid input - " << except.msg_ptr << endl;
		}
	}

	return 0;
}




