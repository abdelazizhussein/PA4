#include "PokemonCenter.h"
#include "GameObject.h"

PokemonCenter::PokemonCenter() : Building('C') { 
	stamina_capacity = 100;
	num_stamina_points_remaining = stamina_capacity;
	dollar_cost_per_stamina_point = 5.0;
	state = STAMINA_POINTS_AVAILABLE;
	cout << "PokemonCenter default constructed"<<endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc) : Building('C', in_id, in_loc) {
	stamina_capacity = 100;
	num_stamina_points_remaining = stamina_capacity;
	dollar_cost_per_stamina_point = 5.0;
	state = STAMINA_POINTS_AVAILABLE;
	cout << "PokemonCenter default constructed" << endl;
}
	return num_stamina_points_remaining;
	if (budget >= (dollar_cost_per_stamina_point*stamina_points)) {
	cout << "Pokemon Center Status : ";