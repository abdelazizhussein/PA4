
#include "Point2D.h"
//#include <iostream>
#include<cmath>
using namespace std;


Point2D::Point2D() {
	x = 0.0;
	y = 0.0;
}
Point2D::Point2D(double in_x, double in_y) {
	x = in_x;
	y = in_y;

}

ostream& operator<<(ostream& out, Point2D& pointer) {
	out << "(" << pointer.x << "," << pointer.y << ")";
	return out;
}

Point2D operator+(Point2D p1, Point2D v1) {
	Point2D out((p1.x + v1.x), (p1.y + v1.y));
	return out;
}

Point2D operator-(Point2D p1, Point2D v1) {
	Point2D out((p1.x - v1.x), (p1.y - v1.y));
	return out;
}

double GetDistanceBetween(Point2D p1, Point2D p2) {	int dif_x = p2.x - p1.x;	dif_x = dif_x * dif_x;	int dif_y = p2.y - p1.y;	dif_y = dif_y * dif_y;	double distance = sqrt(dif_x + dif_y);	return distance;}