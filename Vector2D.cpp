#include<iostream>
using namespace std;
#include"Vector2D.h"


Vector2D::Vector2D() {
	x = 0.0;
	y = 0.0;

}

Vector2D::Vector2D(double in_x, double in_y) {
	x = in_x;
	y = in_y;
}


Vector2D operator*(Vector2D v1, double d) {
	Vector2D v2 ((v1.x) * d, (v1.x) * d);
	return v2;

}

Vector2D operator/(Vector2D v1, double d) {
	Vector2D v2((v1.x) / d, (v1.y) / d);
	return v2;
}

ostream& operator <<(ostream& out, Vector2D v1) {

	out << '<' << v1.x << ',' << v1.y << '>';
	return out;

}

