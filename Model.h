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
	PokemonGym* GetPokemonGymPtr(int id);	Rival* GetRivalPtr(int id);	BattleArena* GetArenaPtr(int id);	void NewPokemon(Pokemon* pokemon);
	void NewPokemonCenter(PokemonCenter* pokemoncenter);
	void NewPokemonGym(PokemonGym* gym);	void NewRival(Rival* rival);	void NewArena(BattleArena* arena);	bool Update();
	void Display(View& view);	void ShowStatus();
private:
	int time;
	list <GameObject*> object_ptrs;
	list<GameObject*> active_ptrs;
	int num_objects;	list<Pokemon*> pokemon_ptrs;		list <PokemonCenter*> center_ptrs;	int num_pokemon;
	int num_centers;
	list <PokemonGym*> gym_ptrs;
		int num_gyms;
	list<Rival*> rival_ptrs;
	int num_rivals;
	list<BattleArena*> arena_ptrs;

	int num_arenas;
};

