#include "GameObject.h"
#include <iostream>
# include "Point2D.h"

using namespace std;

GameObject:: GameObject() {
	
}
GameObject:: ~ GameObject() {
	cout << "GameObject destructed"<<endl;
}

GameObject::GameObject(char in_code) {
	display_code = in_code;
	id_num = 1;
	state = '0';
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code) {
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	state = '0';
}

Point2D GameObject::GetLocation() {
	return location;
}


int GameObject::GetId() {
	return id_num;
}

char GameObject::GetState() {
	return state;
}

void GameObject::ShowStatus() {
	cout << display_code <<id_num<< " located at " << location;   // needs more
}

void GameObject::DrawSelf(char* ptr) {


		*ptr = display_code;
		*(ptr + 1) = char(id_num);
	

}
