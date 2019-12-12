#pragma once
# include "Point2D.h"

class GameObject {
public:
	int GetId();
	char GetState();
	GameObject(char);
	GameObject(Point2D, int, char);
	Point2D GetLocation();
	virtual void ShowStatus(); 
	GameObject();
	~GameObject();
	virtual bool Update() = 0;
	void DrawSelf(char* ptr); 


protected:
	Point2D location;
	int id_num;
	char display_code;
	char state;

};
