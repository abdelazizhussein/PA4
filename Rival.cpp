
#include "Rival.h"
#include<cstdlib>

Rival::Rival(string name, double speed, double hp, double phys_dmg, double
	magic_dmg, double def, int id, Point2D in_loc) :GameObject(in_loc, id, 'R') {

	this->name = name;
	this->speed = speed;
	health = hp;
	physical_damage = phys_dmg;
	magical_damage = magic_dmg;
	defense = def;
	state = ALIVE_RIVAL;


}
Rival::Rival (int id, Point2D in_loc) :GameObject(in_loc, id, 'R') {
	speed = 2;
	defense = 12;
	state = ALIVE_RIVAL;
	stamina_cost_per_fight = 3;
}

void Rival::TakeHit(double physical_damage, double magical_damage, double defense) {
	int num = rand() % 2;
	double damage;
	if (num == 0) {
		damage = (100.0 - defense) / 100;
		damage = damage * physical_damage;

		health -= damage;
		cout << "Aaagh, no Physical Pain no gain!" << endl;
	}
	else {
		damage = (100.0 - defense) / (100);
		damage = damage * magical_damage;
		health -= damage;
		cout << "Ouch, I don't believe in magic!" << endl;
	}
	
	cout << "Damage: " << damage << endl;
	cout << "Health: " << health << endl;
	cout << "********" << endl;

}

double Rival::get_phys_dmg() {
	return physical_damage;
}
double Rival::get_magic_dmg() {
	return magical_damage;
}
double Rival::get_defense() {
	return defense;
}
double Rival::get_health() {
	return health;
}

bool Rival::Is_Alive() {
	if (health <= 0) {
		return false;
	}
	else {
		return true;
	}
}

bool Rival::Update() {
	if (Is_Alive()) {
		state = ALIVE_RIVAL;
		ShowStatus();
		return false;
	}
	else {
		state = FAINTED_RIVAL;
		ShowStatus();
		return true;
	}
	
}

void Rival::ShowStatus() {
	cout << name <<" Status: ";
	GameObject::ShowStatus();
	if (state == ALIVE_RIVAL) {
		cout << " Alive" << endl;
	}
	else {
		cout << " fainted" << endl;
	}
	cout << "	Health: " << health<<endl;
	cout << "	Physical Damage: " << physical_damage << endl;
	cout << "	Magical Damage: " << magical_damage << endl;
	cout << "	Defense: " << defense << endl;
}