#pragma once

#include"GameObject.h"
#include"BattleArena.h"


enum rival_states {
	ALIVE_RIVAL=0,
	FAINTED_RIVAL=1
};

class Rival : public GameObject {
protected:
	double health = 20;
	double physical_damage = 5;
	double magical_damage = 4;
	double defense;
	double stamina_cost_per_fight;
	bool is_in_arena;
	BattleArena* current_arena;
	string name;
	double speed;
public:
	Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc);
	Rival(int id, Point2D loc);
	void TakeHit(double physical_damage, double magical_damage, double defense);
	double get_phys_dmg();
	double get_magic_dmg();
	double get_defense();
	double get_health();
	bool Update();
	void ShowStatus();
	bool Is_Alive();

};
