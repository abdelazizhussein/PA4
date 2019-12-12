#pragma once
#include"GameObject.h"
#include"Pokemon.h"
#include"PokemonCenter.h"
#include"View.h"
#include<list>

class Model
{
public:
	Model();
	~Model();
	Pokemon* GetPokemonPtr(int id);
	PokemonCenter* GetPokemonCenterPtr(int id);
	PokemonGym* GetPokemonGymPtr(int id);
	void NewPokemonCenter(PokemonCenter* pokemoncenter);
	void NewPokemonGym(PokemonGym* gym);
	void Display(View& view);
private:
	int time;
	list <GameObject*> object_ptrs;
	list<GameObject*> active_ptrs;
	int num_objects;
	int num_centers;
	list <PokemonGym*> gym_ptrs;
	
	list<Rival*> rival_ptrs;
	int num_rivals;
	list<BattleArena*> arena_ptrs;

	int num_arenas;
};
