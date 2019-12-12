#pragma once
#pragma once

class Vector2D {
public:
	double x = 0.0;
	double y = 0.0;
	Vector2D();
	Vector2D(double, double);


};


Vector2D operator*(Vector2D v1, double d);
Vector2D operator/(Vector2D v1, double d);
ostream& operator <<(ostream& out, Vector2D v1);