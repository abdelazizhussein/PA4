#include "Pokemon.h"
#include"Point2D.h"
#include "Vector2D.h"

#include"PokemonGym.h"
#include<string.h>
#include<cmath>



Pokemon::Pokemon() {
	speed = 5;
	cout << "Pokemon default constructed." << endl;
	

}
Pokemon::Pokemon(char in_code) : GameObject(in_code) {
	state = STOPPED;
	cout << "Pokemon Constructed" << endl;
	
}
Pokemon::Pokemon(int id, Point2D loc): GameObject('P') {
	speed = 5;
	state = STOPPED;
	cout << "Pokemon default constructed." << endl;
	location = loc;
	id_num = id;
	name = "Newpokemon";
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code) {
	speed = in_speed;
	name = in_name;
	state = STOPPED;
	cout << "Pokemon Constructed" << endl;
}

Pokemon::~Pokemon() {
	cout << "Pokemon destructed" << endl;
}

string Pokemon::GetName() {
	return name;
}

void Pokemon::StartMoving(Point2D dest) {

	if (dest.x == location.x && dest.y == location.y) {
		cout << display_code << id_num << " :I’m already there.See ? " << endl;
	}
	else if (state == EXHAUSTED) {
		cout << display_code << id_num << " :I am exhausted. I may move but you cannot see me. " << endl;
	}
	else if (state == FAINTED) {
		cout << display_code << id_num << " is Dead, cannot move" << endl;
	}
	else {
		if (state == IN_GYM) {
			current_gym->RemoveOnePokemon();
			is_in_gym = false;
		}
		else if (state == IN_CENTER) {
			current_center->RemoveOnePokemon();
			is_in_center = false;

		}
		state = MOVING;
		SetupDestination(dest);
		Point2D delta1;
		double delta2;
		delta1 = destination - location;
		delta2 = speed / GetDistanceBetween(destination, location);
		delta1.x = delta1.x * delta2;
		delta1.y = delta1.y * delta2;
		Vector2D delta3(delta1.x, delta1.y);
		delta = delta3;
		cout << display_code << id_num << " :On my way" << endl;

	}
}

void Pokemon::StartMovingToCenter(PokemonCenter* center) {
	Point2D loc1 = center->GetLocation();

	if (state == EXHAUSTED) {
		cout << display_code << id_num << " :I am exhausted so I can’t move to recover stamina…" << endl;
	}
	else if (state == FAINTED) {
		cout << display_code << id_num << " is Dead, cannot move" << endl;
	}
	else if (loc1.x == location.x && loc1.y == location.y) {
		cout << display_code << id_num << " :I’m already at the Pokemon enter!" << endl;
	}
	else {
		state = MOVING_TO_CENTER;
		current_center = center;
		SetupDestination(center->GetLocation());
		Point2D delta1;
		double delta2;
		delta1 = destination - location;
		delta2 = speed / GetDistanceBetween(destination, location);
		delta1.x = delta1.x * delta2;
		delta1.y = delta1.y * delta2;
		Vector2D delta3(delta1.x, delta1.y);
		delta = delta3;
		cout << display_code << id_num << " : on my way to center " << center->GetId() << endl;
	}

}


void Pokemon::StartMovingToGym(PokemonGym* gym) {
	Point2D loc1 = gym->GetLocation();
	if (state == EXHAUSTED) {
		cout << display_code << id_num << " :I am exhausted so I can’t move to recover stamina…" << endl;
	}
	else if (state == FAINTED) {
		cout << display_code << id_num << " is Dead, cannot move" << endl;
	}
	else if (loc1.x == location.x && loc1.y == location.y) {
		cout << display_code << id_num << " :I’m already at the Pokemon gym!" << endl;
	}
	else {
		state = MOVING_TO_GYM;
		current_gym = gym;
		SetupDestination(gym->GetLocation());
		Point2D delta1;
		double delta2;
		delta1 = destination - location;
		delta2 = speed / GetDistanceBetween(destination, location);
		delta1.x = delta1.x * delta2;
		delta1.y = delta1.y * delta2;
		Vector2D delta3(delta1.x, delta1.y);
		delta = delta3;
		cout << display_code << id_num << " : on my way to gym " << gym->GetId() << endl;
	}
}

void Pokemon::StartMovingToArena(BattleArena* arena) {
	Point2D loc1 = arena->GetLocation();
	if (state == EXHAUSTED) {
		cout << display_code << id_num << " :I am exhausted so I can’t move to recover stamina…" << endl;
	}
	else if(state == FAINTED) {
		cout << display_code << id_num << " is Dead, cannot move"<<endl;
	}
	else if (loc1.x == location.x && loc1.y == location.y) {
		cout << display_code << id_num << " :I’m already at the Arena!" << endl;
	}
	else {
		state = MOVING_TO_ARENA;
		current_arena = arena;
		SetupDestination(arena->GetLocation());
		Point2D delta1;
		double delta2;
		delta1 = destination - location;
		delta2 = speed / GetDistanceBetween(destination, location);
		delta1.x = delta1.x * delta2;
		delta1.y = delta1.y * delta2;
		Vector2D delta3(delta1.x, delta1.y);
		delta = delta3;
		cout << display_code << id_num << " : on my way to arena " << arena->GetId() << endl;
	}
}



void Pokemon::StartTraining(unsigned int num_training_units) {

	if (state != EXHAUSTED) {
		if (is_in_gym) {
			if (current_gym->GetStaminaCost(num_training_units) <= stamina) {
				if (current_gym->GetDollarCost(num_training_units) <= pokemon_dollars) {
					if (!current_gym->IsBeaten()) {
						if (current_gym->GetNumTrainingUnitsRemaining() >= num_training_units) {
							cout << display_code << " : Started to train at Pokemon Gym" << current_gym->GetId() << "with" << num_training_units << "training units" << endl;
							training_units_to_buy = num_training_units;
							state = TRAINING_IN_GYM;
						}
						else {

							cout << display_code << " : Started to train at Pokemon Gym" << current_gym->GetId() << "with" << current_gym->GetNumTrainingUnitsRemaining() << "training units" << endl;
							training_units_to_buy = current_gym->GetNumTrainingUnitsRemaining();
						}

					}
					else {
						cout << display_code << id_num << " : Cannot train! This Pokemon Gym is already beaten!" << endl;
					}
				}
				else {
					cout << display_code << id_num << " : Not enough money for training" << endl;
				}
			}
			else {
				cout << display_code << id_num << " : Not enough stamina for training" << endl;

			}


		}
		else {
			cout << display_code << id_num << " : I can only train in a Pokemon Gym!" << endl;
		}

	}
	else {
		cout << display_code << id_num << " : Pokemon is Exhausted, cannot train" << endl;  // need to change this

	}

}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points) {

	if (is_in_center) {
		if (current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars)) {
			if (current_center->HasStaminaPoints()) {
				state = RECOVERING_STAMINA;
				if (current_center->GetNumStaminaPointsRemaining() >= num_stamina_points) {
					stamina_points_to_buy = num_stamina_points;
				}
				else {
					stamina_points_to_buy = current_center->GetNumStaminaPointsRemaining();
				}
			}
			else {
				cout << display_code << id_num << " :Cannot recover! No stamina points remaining in this Pokemon Center" << endl;
			}
		}
		else {
			cout << display_code << id_num << " : Not enough money to recover stamina" << endl;
		}

	}
	else {
		cout << display_code << id_num << " :I can only recover stamina at a Pokemon Center!" << endl;

	}
}

void Pokemon::Stop() {
	state = STOPPED;
	cout << display_code << id_num << " : stopping.." << endl;
}

bool Pokemon::IsExhausted() {
	if (stamina == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Pokemon::ShouldBeVisible() {
	if (IsExhausted()) {
		return false;
	}
	else {
		return true;
	}
}



bool Pokemon::UpdateLocation() {
	double change_x = destination.x - location.x;
	double change_y = destination.y - location.y;
	change_x = abs(change_x);
	change_y = abs(change_y);
	if (stamina == 0) {
		state = EXHAUSTED;
		cout << name << " is out of stamina and can't move" << endl;
	}
	else {
		if (change_x <= abs(delta.x) && change_y <= abs(delta.y)) {
			location = destination;
			cout << display_code << id_num << ": i'm there!" << endl;
			return true;
		}
		else {
			cout << display_code << id_num << ": step..." << endl;
			location.x = location.x + delta.x;
			location.y = location.y + delta.y;
			stamina -= 1;
			pokemon_dollars += GetRandomAmountOfPokemonDollars();
			return false;
		}
	}
}

void Pokemon::ShowStatus() {
	cout << name << " status: ";
	GameObject::ShowStatus();


	switch (state) {
	case 0: {cout << " stopped" << endl;
		break; }
	case 1: {cout << " moving at speed of " << speed << " to destination" << destination << "at each step of " << delta << endl;
		break; }
	case 2: break;
	case 3: {cout << " inside Pokemon Gym " << current_gym << endl;
		break; }
	case 4: {cout << " inside Pokemon Center " << current_center << endl;
		break; }
	case 5: {cout << " heading to Pokemon Gym " << current_gym << "at a speed of" << speed << "at each step of " << delta << endl;
		break; }
	case 6: {cout << " heading to Pokemon Center " << current_center << "at a speed of" << speed << "at each step of " << delta << endl;
		break; }
	case 7: {cout << " Training in pokemon Gym " << current_gym << endl;
		break; }
	case 8: {cout << " recovering stamina in Pokemon Center " << current_center << endl;
		break; }
	}

	cout << "	Stamina: " << stamina << endl;
	cout << "	PokemonDollars: " << pokemon_dollars << endl;
	cout << "	Experience Points: " << experience_points << endl;
	cout << "	Health: " << health << endl;
	cout << "	Physical Damage: " << physical_damage << endl;
	cout << "	Magical Damage: " << magical_damage << endl;
	cout << "	Defense: " << defense << endl;
}



bool Pokemon::Update() {
	switch (state) {
		case char(0) : {ShowStatus();
			return false; }
					 case char(1) : {
						   UpdateLocation();
						   ShowStatus();
						   if (location.x == destination.x && location.y == destination.y) {
							   state = STOPPED;

							   return true;
						   }
						   else {
							   state = MOVING;
							   return false;
						   }
					   }
									  case char(2) :
										  case char(3) : {ShowStatus();
										  return false; }
												   case char(4) : { ShowStatus();
													   return false; }
																  case char(5) : {
																	  if (UpdateLocation()) {
																		  state = IN_GYM;
																		  is_in_gym = true;

																		  current_gym->AddOnePokemon();
																		  ShowStatus();
																		  return true;
																	  }
																	  else {
																		  ShowStatus();
																		  return false;
																	  }
																  }
																				 case char(6) : {
																					 if (UpdateLocation()) {
																						 state = IN_CENTER;
																						 is_in_center = true;

																						 current_center->AddOnePokemon();
																						 ShowStatus();
																						 return true;
																					 }
																					 else {
																						 ShowStatus();
																						 return false;
																					 }
																				 }
																								case char(7) : {
																									stamina -= current_gym->GetStaminaCost(training_units_to_buy);
																									pokemon_dollars -= current_gym->GetDollarCost(training_units_to_buy);
																									unsigned int exp = current_gym->TrainPokemon(training_units_to_buy);
																									experience_points += exp;
																									cout << "**" << name << " completed " << training_units_to_buy << " training unit(s)! **" << endl;
																									cout << "**" << name << " gained " << exp << " experience point(s)! **" << endl;
																									state = IN_GYM;
																									ShowStatus();
																									return true;
																								}
																											   case char(8) : {
																												   unsigned int stam = current_center->DistributeStamina(stamina_points_to_buy);
																												   stamina += stam;
																												   pokemon_dollars -= current_center->GetDollarCost(stam);
																												   cout << "** " << name << " recovered " << stam << " stamina Point(s)!" << endl;
																												   state = IN_CENTER;
																												   ShowStatus();
																												   return true;
																											   }
																															  case char(9): {}

																																			case char(10): {
																																				if (UpdateLocation()) {
																																					state = IN_ARENA;
																																					current_arena->AddOnePokemon();
																																					is_in_arena = true;
																																					ShowStatus();
																																					return true;
																																				}
																																				else {
																																					ShowStatus();
																																					return false;
																																				}
																																			}
																																						   case char(11) : {
																																							   stamina -= current_arena->GetStaminaCost();
																																							   pokemon_dollars -= current_arena->GetDollarCost();
																																							   bool won = StartBattle();
																																							   if (won) {
																																								   health = store_health;
																																								   state = IN_ARENA;
																																								   target->Is_Alive();
																																								   cout << "Congrats Master, you defeated one rival!" << endl;
																																							   }
																																							   else {
																																								   state = FAINTED;
								
																																								   target->Is_Alive();
																																								   cout << " Master, you have been defeated!" << endl;
																																							   }

																																						   }
																																										   case char(12) : {
																																											   ShowStatus();
																																											   return false;
																																										   }









	}


}

void Pokemon::SetupDestination(Point2D dest) {
	destination = dest;
}



Pokemon::Pokemon(string in_name, double speed, double hp, double phys_dmg, double
	magic_dmg, double def, int in_id, char in_code, Point2D in_loc) :
	GameObject(in_loc, in_id, 'P') {
	name = in_name;
	this->speed = speed;
	health = hp;
	physical_damage = phys_dmg;
	magical_damage = magic_dmg;
	defense = def;
	state = STOPPED;


}

bool Pokemon::IsAlive() {
	if (state == FAINTED) {
		return false;
	}
	else {
		return true;
	}

}

void Pokemon::TakeHit(double physical_damage, double magical_damage, double defense) {
	int num = rand() % 2;
	double damage;
	if (num == 0) {
		damage = (100.0 - defense) / (100);
		damage = damage * physical_damage;

		health -= damage;
		cout << "Physical damage hurts, Master!" << endl;
	}
	else {
		damage = (100.0 - defense) / (100 );
		damage = damage * magical_damage;
		health -= damage;
		cout << "It is magic, Master!" << endl;
	}
	
	cout << "Damage: " << damage << endl;
	cout << "Health: " << health << endl;
	cout << "********" << endl;
}

void Pokemon::ReadyBattle(Rival* in_target) {
	if (state == IN_ARENA && current_arena->IsAbleToFight(pokemon_dollars,stamina)&& !(current_arena->IsBeaten()) && in_target->Is_Alive()) {
		target = in_target;
		state = BATTLE;
	}
	else {

		state = IN_ARENA;
	}
}

bool Pokemon::StartBattle() {
	bool pokemon_died = false;

	while (health > 0 && target->get_health() > 0) {
		TakeHit(physical_damage, magical_damage, defense);
		if (health < 0) {
			pokemon_died = true;
			break;
		}
		target->TakeHit(target->get_phys_dmg(), target->get_magic_dmg(), target->get_defense());
		if (target->get_health() < 0) {
			break;
		}
	}
	stamina -= current_arena->GetStaminaCost();
	pokemon_dollars -= current_arena->GetDollarCost();
	if (!pokemon_died)
	{
		return true;
	}
	else {
		return false;
	}



}
