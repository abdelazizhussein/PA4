#pragma once

#include "Point2D.h"
#include"GameObject.h"

const int view_maxsize = 20;

class View {
public:
	View();
	void Clear();	void Plot(GameObject* ptr);
	void Draw();
private:
	int size;	double scale;	Point2D origin;
	char grid[view_maxsize][41][2]; //41 here because of how i am doing my plot function. this is still 20x20 but because all the spaces i have inbetween dotts count as a col and the col with scale and its space
	// there is a total of maxsize+(maxsize-1)+2                maxsize-1 is the num of space if there are two dots one space is in between the 2 accounts for the first col and its space
	bool GetSubscripts(int& out_x, int& out_y, Point2D location);
};