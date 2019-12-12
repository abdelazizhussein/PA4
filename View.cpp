
#include "View.h"
#include"Pokemon.h"

View::View() {
	size = 11;
	scale = 2;
	Point2D orig(0, 0);
	origin = orig;

	for (int i = 0; i < view_maxsize; i++) {
		for (int j = 0; j < 41; j++) {
			for (int k = 0; k < 2; k++) {
				if (k == 0) {
					grid[i][j][k] = '.';
				}
				else {
					grid[i][j][1] = NULL;
				}

			}
		}
	}
}

void View::Draw() {

	int col = size + (size - 1);
	col += 2;
	int n = 0;
	int c = (size - 1) * scale;

	for (int i = 0; i < size + 1; i++) {
		for (int j = 0; j < (col); j++) {
			if ((size % 2)) {
				if (i == size) {
					if (j == 0) {
						if (i % 2) {
							cout << " ";
							c -= scale;
						}
						else {
							cout << c;
							c -= scale;
						}
					}
					else if (j == 1) {

						cout << " ";

					}
					else if (j == 2) {
						cout << n;
						n += scale;
					}
					else {
						if (n > 9) {
							if (j % 2) {
								cout << "  ";
								n += scale;
								j += 2;
							}
							else {
								cout << n;
								n += scale;

							}
						}
						else {
							if (j % 2) {
								cout << "   ";
								n += scale;
								j += 2;
							}
							else {
								cout << n;
								n += scale;

							}
						}
					}
				}
				else {
					if (j == 0) {
						if (i % 2) {
							cout << " ";
							c -= scale;
						}
						else {
							cout << c;
							c -= scale;
						}
					}

					else if (j % 2) {
						if (j == 1 && c > 9 && !(i % 2)) {}
						else {
							if(grid[i][j-1][0]!='.'){}
							else {
								cout << " ";
							}
							
						}
					}
					else {
						cout << grid[i][j][0];
						if (grid[i][j][1] != NULL) {
							cout << int(grid[i][j][1]);   //cast char into int
						}
					}
				}

			}
			else {
				if (i == size) {
					if (j == 0) {
						if (i % 2) {
							cout << c;
							c -= scale;
						}
						else {
							cout << " ";
							c -= scale;
						}
					}
					else if (j == 1) {

						cout << " ";

					}
					else if (j == 2) {
						cout << n;
						n += scale;
					}
					else {
						if (n > 10) {
							if (j % 2) {
								cout << "  ";
								n += scale;
								j += 2;
							}
							else {
								cout << n;
								n += scale;

							}
						}
						else {
							if (j % 2) {
								cout << "   ";
								n += scale;
								j += 2;
							}
							else {
								cout << n;
								n += scale;

							}
						}
					}
				}
				else {
					if (j == 0) {

						if (i % 2) {
							cout << c;
							c -= scale;
						}
						else {
							cout << " ";
							c -= scale;
						}
					}
					else if (!(j % 2)) {
						cout << grid[i][j][0] ;
						if (grid[i][j][1] != NULL) {
							cout << int(grid[i][j][1])
								;
						}
					}
					else {
						if (j == 1 && c > 9 && i % 2) {
						}
						else {
							cout << " ";
						}
					}
				}
			}

		}
		cout << endl;
	}
}


bool View::GetSubscripts(int& out_x, int& out_y, Point2D location) {
	out_x = location.x - origin.x;
	out_x = out_x / scale;
	out_y = location.y - origin.y;
	out_y = out_y / scale;

	int max= (size - 1) * scale;
	if (out_x > max || out_y > max) {
		cout << "An object is outside the display" << endl;
		return false;

	}
	else {
		return true;
	}


}

void View::Plot(GameObject* ptr) {
	int x;
	int y;
	int r;
	if (GetSubscripts(x, y, ptr->GetLocation())) {
		r = size - 1; // adjusting for my scale as my 0 is at index 2 due to column with scale
		y = r - y;
		x = 2 * (x + 1);
			ptr->DrawSelf(&(grid[y][x][0]));
	
		
		char obj = grid[y][x][0];
		
		
		int id = ptr->GetId();
		for (int i = 0; i < view_maxsize; i++) {                        // this is called after each update of location for an object. if it already exists on the board with a different location
			for (int j = 0; j < view_maxsize; j++) {                    // that old location gets deleted in grid and only the new location has the id and char specifier to object
				if (grid[i][j][0]==obj) {
					if (grid[i][j][1] == id) {
						if (i == y && j == x) {}
						else {
							grid[i][j][0] = '.';
							grid[i][j][1] = NULL;

						}
					}
				}
			}
		}

	}
}

	


void View::Clear() {
	for (int i = 0; i < view_maxsize; i++) {
		for (int j = 0; j < view_maxsize; j++) {
			for (int k = 0; k < 2; k++) {
				if (k == 0) {
					grid[i][j][k] = '.';
				}
				else {
					grid[i][j][1] = NULL;
				}

			}
		}
	}
}