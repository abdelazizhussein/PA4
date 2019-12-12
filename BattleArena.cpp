#include"BattleArena.h"
#include"Point2D.h"
#include"Model.h"



BattleArena::BattleArena() {
	display_code = 'A';
	pokemon_count = 0;
	max_num_rivals=3;
	num_rivals_remaining = max_num_rivals;
	dollar_cost_per_fight = 4;
	stamina_cost_per_fight = 3;
	state = RIVALS_AVAILABLE;
	cout << "BattleArena default constructed"<<endl;

}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int
	in_Id, Point2D in_loc) : Building ('A' , in_Id,in_loc ) {
	pokemon_count = 0;
	max_num_rivals=max_rivals;
	num_rivals_remaining = max_num_rivals;
	dollar_cost_per_fight = dollar_cost;
	stamina_cost_per_fight = stamina_cost;
	state = RIVALS_AVAILABLE;
	cout << "BattleArena default constructed" << endl;

}
BattleArena::BattleArena(int id, Point2D loc) {
	display_code = 'A';
	pokemon_count = 0;
	max_num_rivals = 3;
	num_rivals_remaining = max_num_rivals;
	dollar_cost_per_fight = 4;
	stamina_cost_per_fight = 3;
	state = RIVALS_AVAILABLE;
	location = loc;
	id_num = id;
	cout << "BattleArena default constructed" << endl;
}

unsigned int BattleArena::GetNumRivalsRemaining() {
	return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals() {
	if (num_rivals_remaining > 0) {
		return true;
	}
	else {
		return false;
	}
}
double BattleArena::GetDollarCost() {
	return dollar_cost_per_fight;

}

unsigned int BattleArena::GetStaminaCost() {
	return stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina) {
	if (budget > stamina_cost_per_fight) {
		if (stamina > stamina_cost_per_fight) {
			return true;
		}
	}
	else{
		return false;
	}

}
bool BattleArena::IsBeaten() {
	if (num_rivals_remaining == 0) {
		return true;
	}
	else {
		return false;
	}
}

void BattleArena::ShowStatus() {
	cout << "Battle Arena: ";
	GameObject::ShowStatus();
	cout << endl;
	cout << "	Max number of rivals: " << max_num_rivals<<endl;
	cout << "	Stamina cost per fight: " << stamina_cost_per_fight<<endl;
	cout << "	Pokemon dollar per fight: " << dollar_cost_per_fight<<endl;
	cout <<"	" <<num_rivals_remaining << " rival(s) remaining for this arena" << endl;
}

bool BattleArena::Update() {
	if (state == NO_RIVALS_AVAILABLE) {
		ShowStatus();
		return false;
	}
	else {
		if (num_rivals_remaining > 0) {
			state = RIVALS_AVAILABLE;
			ShowStatus();
			return false;
		}
		else {
			state = NO_RIVALS_AVAILABLE;
			ShowStatus();
			return true;
		}
	}
	
}

