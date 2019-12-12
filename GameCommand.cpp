#include"GameCommand.h"
#include"Input_Handling.h"
#include"Model.h"
void DoMoveCommand(Model& model, int pokemon_id, Point2D p1) {
	Pokemon* ptr_p = model.GetPokemonPtr(pokemon_id);
	if (ptr_p == NULL) {
		cout << "Error: Please enter a valid command!" << endl;
	}
	else {
		cout << "Moving " << ptr_p->GetName() << " to " << p1 << endl;
		ptr_p->StartMoving(p1);
		
	}
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id) {
	Pokemon* ptr_p = model.GetPokemonPtr(pokemon_id);
	PokemonCenter* ptr_c = model.GetPokemonCenterPtr(center_id);
	if (ptr_p == NULL || ptr_c ==NULL) {
		cout << "Error: Please enter a valid command!" << endl;
	}
	else {
		cout << "Moving " << ptr_p->GetName() << " to center " << ptr_c->GetId()<<endl;
		ptr_p->StartMovingToCenter(ptr_c);
		
	}

}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id) {
	Pokemon* ptr_p = model.GetPokemonPtr(pokemon_id);
	PokemonGym* ptr_g = model.GetPokemonGymPtr(gym_id);
	if (ptr_p == NULL || ptr_g == NULL) {
		cout << "Error: Please enter a valid command!" << endl;
	}
	else {
		cout << "Moving " << ptr_p->GetName() << " to gym " << ptr_g->GetId() << endl;
		ptr_p->StartMovingToGym(ptr_g);
		
	}
}

void DoStopCommand(Model& model, int pokemon_id) {
	Pokemon* ptr_p = model.GetPokemonPtr(pokemon_id);
	if (ptr_p == NULL) {
		cout << "Error: Please enter a valid command!" << endl;
	}
	else {
		cout << "Stopping " << ptr_p->GetName() << endl;
		ptr_p->Stop();
		
	}
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units) {
	Pokemon* ptr_p = model.GetPokemonPtr(pokemon_id);
	if (ptr_p == NULL || training_units < 0 ) {
		cout << "Error: Please enter a valid command!" << endl;
	}
	else {
		cout << "Training " << ptr_p->GetName() << endl;
		ptr_p->StartTraining(training_units);
		
	}
}

void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points) {
	Pokemon* ptr_p = model.GetPokemonPtr(pokemon_id);
	if (ptr_p == NULL || stamina_points < 0) {
		cout << "Error: Please enter a valid command!" << endl;
	}
	else {
		cout << "Recovering " << ptr_p->GetName() << "'s stamina" << endl;
		ptr_p->StartRecoveringStamina(stamina_points);
		
	}
}


void DoGoCommand(Model& model, View& view) {
	cout << "Advancing one tick." << endl;
	model.Update();
	//model.Display(view);
	

}

void DoRunCommand(Model& model, View& view) {
	int t = 0;
	bool ans = false;
	while (t < 5) {
		cout << "Advancing to next event." << endl;
		ans = model.Update();
		if (ans) {
			break;
		}
		else {
			t += 1;
			continue;
		}
	
	}
	
	
}

void Battle(Model& model, int pokemon_id, int rival_id) {
	Pokemon* ptr1 = model.GetPokemonPtr(pokemon_id);
	Rival* ptr2 = model.GetRivalPtr(rival_id);
	if (ptr1 == NULL || ptr2 == NULL) {
		cout << "Error: Please enter a valid command!" << endl;
	}
	else {
		if (ptr1->GetState() == IN_ARENA) {
			cout <<  ptr1->GetName() << " Getting ready for the battle " << endl;
			ptr1->ReadyBattle(ptr2);
		}
		else {
			cout <<ptr1->GetName() <<" I can only fight in a Battle Arena!" << endl;
		}
	}

}

void DoMoveToArenaCommand(Model& model, int pokemon_id, int arena_id) {
	Pokemon* ptr1 = model.GetPokemonPtr(pokemon_id);
	BattleArena* ptr2 = model.GetArenaPtr(arena_id);
	if ( ptr1 == NULL ||ptr2 == NULL) {
		cout << "Error: Please enter a valid command!" << endl;
	}

	else {
		cout << "Moving " << ptr1->GetName() << " to Arena " << ptr2->GetId() << endl;
		ptr1->StartMovingToArena(ptr2);
	}

}
void NewCommand(Model& model, int id, char type, double x, double y) {

		if (type == 'g') {
			PokemonGym* gym = model.GetPokemonGymPtr(id);
			if (gym == NULL)
			{
				Point2D loc(x, y);
				PokemonGym* gym1 = new PokemonGym(id, loc);
				model.NewPokemonGym(gym1);
			}
			else {
				throw Invalid_Input("Gym already exists!");
			}
		}
		else if (type == 'c') {
			PokemonCenter* center = model.GetPokemonCenterPtr(id);
			if (center == NULL)
			{
				Point2D loc(x, y);
				PokemonCenter* center1 = new PokemonCenter(id, loc);
				model.NewPokemonCenter(center1);
			}
			else {
				throw Invalid_Input("Center already exists!");
			}

		}
		else if (type == 'p') {
			Pokemon* pokemon = model.GetPokemonPtr(id);
			if (pokemon == NULL)
			{
				Point2D loc(x, y);
				Pokemon* Pokemon1 = new Pokemon(id, loc);
				model.NewPokemon(Pokemon1);
			}
			else {
				throw Invalid_Input("Center already exists!");
			}
		}
		else if (type == 'r') {
			Rival* rival = model.GetRivalPtr(id);
			if (rival == NULL)
			{
				Point2D loc(x, y);
				Rival* rival1 = new Rival(id, loc);
				model.NewRival(rival1);
			}
			else {
				throw Invalid_Input("Center already exists!");
			}
		}
		else if (type == 'a') {
			BattleArena* arena = model.GetArenaPtr(id);
			if (arena == NULL)
			{
				Point2D loc(x, y);
				BattleArena* arena1 = new BattleArena(id, loc);
				model.NewArena(arena1);
			}
			else {
				throw Invalid_Input("Center already exists!");
			}
		}
		else {
			throw Invalid_Input("invalid object type!");
		}
	
}