#include"PokemonGym.h"
#include "Building.h"

PokemonGym::PokemonGym(): Building('G') {
	state = NOT_BEATEN;
	max_number_of_training_units = 10;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = 1;
	dollar_cost_per_training_unit = 1.0;
	experience_points_per_training_unit = 2;
	

	
	cout << "PokemonGym default constructed"<<endl;
}

PokemonGym::PokemonGym (unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc) : Building('G', in_id, in_loc) {
	state = NOT_BEATEN;
	max_number_of_training_units = 10;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = 1;
	dollar_cost_per_training_unit = 1.0;
	experience_points_per_training_unit = 2;
	cout << "PokemonGym default constructed" << endl;
}
	cout << "Pokemon Gym Status : "; 
	Building::ShowStatus();

	cout << "	Max number of training units : " << max_number_of_training_units <<endl;
	cout <<	"	Stamina cost per training unit: " << stamina_cost_per_training_unit<<endl;
	cout <<	"	Pokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
	cout << "	Experience points per training unit : " << experience_points_per_training_unit << endl;
	cout << "	"<<num_training_units_remaining << " " << "training unit(s) are remaining for this gym" << endl;
}

