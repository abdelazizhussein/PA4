#include<iostream>
#include"Point2D.h"
#include"Building.h"
#include"GameObject.h"
#include"PokemonCenter.h"
#include"PokemonGym.h"
#include"GameCommand.h"
#include"BattleArena.h"
#include<ctime>
#include"Input_Handling.h"

using namespace std;
double GetDistanceBetween(Point2D p1, Point2D p2);



int main() {

	srand(time(NULL));
	cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2019" << endl;
	cout << "Programming Assignment 3" << endl;

	cout << R"(
                                  ,'\
    _.----.        ____         ,'  _\   ___    ___     ____
_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
 \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
        \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                                `'                            '-._|
                                )"
		<< '\n';

	Model model1;
	View view1;
	
	bool valid;
	string commands[11] = { "m","g","c","s","r","t","v","x","q","a","b" };

	model1.ShowStatus();
	
	while (true) {
		model1.Display(view1);
		string com;
		cout << "Enter command: ";
		cin >> com;
		try {


			 if (com.length() > 1) {
				throw Invalid_Input("command is only one letter!");
			}
			else {
				if (com == "m") {
					int ID;
					double x, y;
					cin >> ID;
					cin >> x;
					cin >> y;
					if (cin.fail()) {
						throw Invalid_Input("invalid parammeters!");
					
					}
					else {
						Point2D loc(x, y);
						DoMoveCommand(model1, ID, loc);
					}

				}
				else if (com == "g") {
					int ID1, ID2;
					cin >> ID1 >> ID2;
					if (cin.fail()) {
						throw Invalid_Input("invalid parammeters!");
					}
					else {
						DoMoveToGymCommand(model1, ID1, ID2);
					}

				}
				else if (com == "c") {
					int ID1, ID2;
					cin >> ID1 >> ID2;
					if (cin.fail()) {
						throw Invalid_Input("invalid parammeters!");
					}
					else {
						DoMoveToCenterCommand(model1, ID1, ID2);
					}
				}
				else if (com == "s") {
					int ID;
					cin >> ID;
					if (cin.fail()) {
						throw Invalid_Input("invalid parammeters!");
					}
					else {
						DoStopCommand(model1, ID);
					}
				}
				else if (com == "r") {
					int ID1;
					unsigned int stamina_amount;
					cin >> ID1 >> stamina_amount;
					if (cin.fail()) {
						throw Invalid_Input("invalid parammeters!");
					}
					else {
						DoRecoverInCenterCommand(model1, ID1, stamina_amount);
					}
				}
				else if (com == "t") {
					int ID1;
					unsigned int unit_amount;
					cin >> ID1 >> unit_amount;
					if (cin.fail()) {
						throw Invalid_Input("invalid parammeters!");
					}
					else {
						DoTrainInGymCommand(model1, ID1, unit_amount);
					}
				}
				else if (com == "v") {
					DoGoCommand(model1, view1);
				}
				else if (com == "x") {
					DoRunCommand(model1, view1);
				}
				else if (com == "q") {
					break;
				}
				else if (com == "b") {
					int ID1, ID2;
					cin >> ID1 >> ID2;
					if (cin.fail()) {
						throw Invalid_Input("invalid parammeters!");
					}
					else {
						Battle(model1, ID1, ID2);
					}
				}

				else if (com == "a") {
					int ID1, ID2;
					cin >> ID1 >> ID2;
					if (cin.fail()) {
						throw Invalid_Input("invalid parammeters!");
					}
					else {
						DoMoveToArenaCommand(model1, ID1, ID2);
					}
				}
				else if (com == "n") {
					char type;
					int id, x, y;
					cin >> type >> id>> x >> y;
					if (cin.fail()) {
						throw Invalid_Input("invalid parammeters!");
					}
					else {
						NewCommand(model1, id, type, x, y);
					}
				}
				else {
					throw Invalid_Input( "invalid command!");
				}

			}



		}
		catch (Invalid_Input& except ) {
			cout << "Invalid input : " << except.msg_ptr<<endl;
			cin.clear();
			cin.ignore(100, '\n');

		}


	}
	return 0;

}
