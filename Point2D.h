#pragma once
#pragma once
#include <iostream>
using namespace std;

class Point2D {
public:
	double x = 0;
	double y = 0;

	Point2D();
	Point2D(double, double);

};
Point2D operator-(Point2D p1, Point2D v1);
double GetDistanceBetween(Point2D , Point2D );
ostream& operator<<(ostream& out, Point2D& pointer);
Point2D operator+(Point2D p1, Point2D v1);
