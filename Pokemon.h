#pragma once
#include"GameObject.h"
#include"PokemonCenter.h"
#include"PokemonGym.h"
#include "Vector2D.h"
#include<time.h>
#include"Rival.h"
#include<cstdlib>
#include<cmath>


enum PokemonStates {
	STOPPED = 0,
	MOVING = 1,
	EXHAUSTED = 2,
	IN_GYM = 3,
	IN_CENTER = 4,
	MOVING_TO_GYM = 5,
	MOVING_TO_CENTER = 6,
	TRAINING_IN_GYM = 7,
	RECOVERING_STAMINA = 8,
	IN_ARENA = 9,
	MOVING_TO_ARENA = 10,
	BATTLE = 11,
	FAINTED = 12
};
class Pokemon : public GameObject {
public:
	Pokemon();
	Pokemon(char in_code);
	Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
	Pokemon(int id, Point2D loc);
	~Pokemon();
	void StartMoving(Point2D dest);
	void StartMovingToCenter(PokemonCenter* center);
	void StartMovingToGym(PokemonGym* gym);
	void StartMovingToArena(BattleArena* arena);
	void StartTraining(unsigned int num_training_units);
	void StartRecoveringStamina(unsigned int num_stamina_points);
	void Stop();
	bool IsExhausted();
	bool ShouldBeVisible();	void ShowStatus();	bool Update();	string GetName();	Pokemon(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc);
	bool IsAlive();
	void TakeHit(double physical_damage, double magical_damage, double defense);
	void ReadyBattle(Rival* in_target);
	bool StartBattle();protected:	bool UpdateLocation();	void SetupDestination(Point2D dest);	double health = 20;
	double store_health = health;
	double physical_damage = 5;
	double magical_damage = 4;
	double defense;	Rival* target;
	bool is_in_arena;
	BattleArena* current_arena;private:	double speed;	bool is_in_gym = false;	bool is_in_center = false;	unsigned int stamina = 20;	unsigned int experience_points = 0;	double pokemon_dollars = 0.0;
	unsigned int training_units_to_buy = 0;
	unsigned int stamina_points_to_buy = 0;
	string name;
	PokemonCenter* current_center;
	PokemonGym* current_gym;	Point2D destination;	Vector2D delta;
};

static double GetRandomAmountOfPokemonDollars() {
	srand(time(0));
	double f = fmod(((double)rand()), 3);
	return f;
}