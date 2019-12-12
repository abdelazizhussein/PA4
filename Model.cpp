#include"Model.h"
#include"Pokemon.h"
#include "PokemonCenter.h"
#include"PokemonGym.h"
#include "Point2D.h"
#include "View.h"



Model::Model() {
	time = 0;
	Point2D loc(5.0, 1.0);
	Pokemon* Pokemon1 = new Pokemon("Pikachu", 2, 23 ,3,6,12,1, 'P', loc);
	Point2D loc1(10.0, 1.0);
	Pokemon* Pokemon2 = new Pokemon("Bulbasaur",1,26,4,3.7,16, 2, 'P', loc1);
	Point2D loc2(1.0, 20.0);
	PokemonCenter* PokemonCenter1 = new PokemonCenter(1, 1, 100, loc2);
	Point2D loc3(10.0, 20.0);
	PokemonCenter* PokemonCenter2 = new PokemonCenter(2, 2, 200, loc3);
	Point2D loc4(0.0, 0.0);
	PokemonGym* PokemonGym1 = new PokemonGym(10, 1, 2.0, 3, 1, loc4);
	Point2D loc5(5.0, 5.0);
	PokemonGym* PokemonGym2 = new PokemonGym(20, 5, 7.5, 8, 2, loc5);
	Point2D loc6(15.0, 12.0);
	Rival* rival1 = new Rival("burhack", 2, 16, 3, 7.2, 20, 1, loc6);
	Rival* rival3 = new Rival("Densmore(aka BigBoss)", 2, 41, 6, 8.2, 18, 3, loc6);
	Rival* rival2 = new Rival("mmark9", 2, 29, 4, 5.2, 12, 2, loc6);
	BattleArena* arena1 = new BattleArena(3, 3, 3, 1, loc6);


	object_ptrs.push_back(Pokemon1);
	active_ptrs.push_back(Pokemon1);

	pokemon_ptrs.push_back(Pokemon1);


	object_ptrs.push_back(Pokemon2);
	active_ptrs.push_back(Pokemon2);

	pokemon_ptrs.push_back(Pokemon2);


	object_ptrs.push_back(PokemonCenter1);
	active_ptrs.push_back(PokemonCenter1);

	center_ptrs.push_back(PokemonCenter1);


	object_ptrs.push_back(PokemonCenter2);
	active_ptrs.push_back(PokemonCenter2);
	
	center_ptrs.push_back(PokemonCenter2);


	object_ptrs.push_back(PokemonGym1);
	active_ptrs.push_back(PokemonGym1);
	
	gym_ptrs.push_back(PokemonGym1);
	

	object_ptrs.push_back(PokemonGym2);
	active_ptrs.push_back(PokemonGym2);

	gym_ptrs.push_back(PokemonGym2);
	

	object_ptrs.push_back(rival1);
	object_ptrs.push_back(rival2);
	object_ptrs.push_back(rival3);
	active_ptrs.push_back(rival1);
	active_ptrs.push_back(rival2);
	active_ptrs.push_back(rival3);

	object_ptrs.push_back(arena1);
	active_ptrs.push_back(arena1);

	rival_ptrs.push_back(rival1);
	rival_ptrs.push_back(rival2);
	rival_ptrs.push_back(rival3);
	arena_ptrs.push_back(arena1);
	


	num_arenas = 1;
	num_rivals = 1;
	num_objects = 8;
	num_pokemon = 2;
	num_centers = 2;
	num_gyms = 2;
	cout << "Model default constructed" << endl;

}

Model::~Model() {
	for (list<Pokemon*>::iterator i = pokemon_ptrs.begin(); i != pokemon_ptrs.end();i++) {
		delete (*i);
	}
	for (list<PokemonCenter*>::iterator i = center_ptrs.begin(); i != center_ptrs.end() ;i++) {
		delete (*i);
	}
	for (list<PokemonGym*>::iterator i = gym_ptrs.begin(); i != gym_ptrs.end(); i++) {
		delete (*i);
	}
}


Pokemon* Model::GetPokemonPtr(int id) {
	for (list<Pokemon*>::iterator i = pokemon_ptrs.begin(); i != pokemon_ptrs.end(); i++) {
		if ((*i)-> GetId() == id) {
			return *i;
		}
	}
	return 0;

}

PokemonCenter* Model::GetPokemonCenterPtr(int id) {
	for (list<PokemonCenter*>::iterator i = center_ptrs.begin(); i != center_ptrs.end(); i++) {
		if ((*i)->GetId() == id) {
			return (*i);
		}
	}
	return 0;

}

PokemonGym* Model::GetPokemonGymPtr(int id) {
	for (list<PokemonGym*>::iterator i = gym_ptrs.begin(); i != gym_ptrs.end(); i ++ ) {
		if (((*i)->GetId()) == id) {
			return (*i);
		}
	}
	return 0;

}
Rival* Model::GetRivalPtr(int id) {
	for (list<Rival*>::iterator i = rival_ptrs.begin(); i != rival_ptrs.end(); i++) {
		if ((*i)->GetId() == id) {
			return (*i);
		}
		else {
			
			return 0;
		}
	}
}
BattleArena* Model:: GetArenaPtr(int id) {
	for (list<BattleArena*>::iterator i = arena_ptrs.begin(); i != arena_ptrs.end(); i++) {
		if ((*i)->GetId() == id) {
			return (*i);
		}
		else {
			return 0;
		}
	}
}

bool Model::Update() {
	time += 1;
	cout << "Time: " << time << endl;
	bool ans = false;

	
	for (list<GameObject*>::iterator i =active_ptrs.begin() ; i != active_ptrs.end();) {
		if ((*i)->GetState() == FAINTED || (*i)->GetState() == FAINTED_RIVAL) {
			i = active_ptrs.erase(i);
		}
		else {
			i++;
		}
	}
	for (list<GameObject*>::iterator i=object_ptrs.begin(); i != object_ptrs.end(); i++) {
		bool ans1 = (*i)->Update();
		if (ans1) {
			ans = true;
		}
		int gym_beaten = 0;
		for (list<PokemonGym*>::iterator i = gym_ptrs.begin(); i != gym_ptrs.end(); i ++) {
			if ((*i)->IsBeaten()) {
				gym_beaten++;
			}
		}
		if (gym_beaten == gym_ptrs.size()) {
			cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
			exit(0);
		}

		int pk_exhausted = 0;

		for (list<Pokemon*>::iterator i = pokemon_ptrs.begin(); i != pokemon_ptrs.end(); i++) {
			if ((*i)->IsExhausted()) {
				pk_exhausted += 1; //error here
			}
		}
		if (pk_exhausted == pokemon_ptrs.size()) {
			cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
			exit(0);
		}

	}
	return ans;

}

void Model::Display(View& view) {
	for (list<GameObject*>::iterator i = active_ptrs.begin(); i != active_ptrs.end(); i++) {
		view.Plot(*i);
	}
	view.Draw();
}

void Model::ShowStatus() {
	cout << "Time: " << time << endl;
	for (list<GameObject*>::iterator i = object_ptrs.begin(); i != object_ptrs.end(); i++) {
		(*i)->ShowStatus();
	}
}

void Model::NewPokemon(Pokemon* pokemon1) {
	object_ptrs.push_back(pokemon1);
	active_ptrs.push_back(pokemon1);
	pokemon_ptrs.push_back(pokemon1);

}

void Model::NewPokemonGym(PokemonGym* gym1) {
	object_ptrs.push_back(gym1);
	active_ptrs.push_back(gym1);
	gym_ptrs.push_back(gym1);
}

void Model::NewPokemonCenter(PokemonCenter* center1) {
	object_ptrs.push_back(center1);
	active_ptrs.push_back(center1);
	center_ptrs.push_back(center1);
}

void Model::NewRival(Rival* rival1) {
	object_ptrs.push_back(rival1);
	active_ptrs.push_back(rival1);
	rival_ptrs.push_back(rival1);
}

void Model::NewArena(BattleArena* arena1) {
	object_ptrs.push_back(arena1);
	active_ptrs.push_back(arena1);
	arena_ptrs.push_back(arena1);
}