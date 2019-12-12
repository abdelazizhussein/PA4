#pragma once
#include "GameObject.h"
#include "Point2D.h"

class Building : public GameObject {
private:
	unsigned int pokemon_count;


public:
	void AddOnePokemon();
	void RemoveOnePokemon();
	virtual void ShowStatus();
	virtual bool ShouldBeVisible();
	Building();
	Building(char in_code);
	Building(char, int, Point2D);
};