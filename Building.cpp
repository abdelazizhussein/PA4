#include"Building.h"
#include "Point2D.h"
#include "GameObject.h"


Building::Building() :GameObject('B') {
	pokemon_count = 0;
	cout << "Building default constructed"<<endl;
}

Building::Building(char in_code): GameObject(in_code) {
	pokemon_count = 0;
	cout << "Building constructed" << endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc) : GameObject(in_loc, in_Id, in_code) {
	pokemon_count = 0;
	cout << "Building constructed"<<endl;

}

void Building::AddOnePokemon() {
	pokemon_count+=1;

}

void Building::RemoveOnePokemon() {
	pokemon_count = pokemon_count - 1;
}
void Building::ShowStatus() {
	GameObject::ShowStatus();
	cout << endl;
	if (pokemon_count < 2 && pokemon_count >0) {
		cout<< "	" << pokemon_count << " " << "Pokemon is in this building"<<endl;
	}
	else {
		cout <<"	"<< pokemon_count << " " << "Pokemon are in this building"<<endl;
	}
}

bool Building::ShouldBeVisible() {
	return true;
}
