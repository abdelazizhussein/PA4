#pragma once
#include"Building.h"
#include"Point2D.h"

enum BattleArenaStates {
	RIVALS_AVAILABLE = 0,
	NO_RIVALS_AVAILABLE = 1
};


class BattleArena: public Building {
private:
	unsigned int max_num_rivals = 3;
	unsigned int num_rivals_remaining= max_num_rivals; 
	double dollar_cost_per_fight;
	unsigned int stamina_cost_per_fight;
	unsigned int pokemon_count;
public:
	BattleArena();
	BattleArena(unsigned int max_rivals, unsigned int stamina_cost, 
	bool IsBeaten();
	void ShowStatus();
};