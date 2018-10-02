
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

// use these to generate random velocity||distance in gaussian curve
static float vel_mean = 17.8;
static float Manualvel_dev = 4.0;
static float AutonVel_dev = 1.0;

static float distance_mean = 4.0;
static float Manualdistance_dev = 2.5;
static float autonDistance_dev = 1.0;

// use these to generate a random number in uniform fashion
static float lane_min = 1.1;
static float lane_max = 2.9;
static float position_min = 25.0;
static float position_max = 125.0;

// to adjust the settings && conditions for the simulation
static float seconds_for_simulation = 30.0;
static int total_cars = 100;
static float percentage_of_auton = .10;
static int number_of_auton = total_cars * percentage_of_auton;
static int number_of_manual = total_cars - number_of_auton;


// more forward declarations 
float bellCurve(float mean, float deviation);
float uniformNumber(float minimum, float maximum);
class Car;
bool car_difLane(Car** allcars, Car* currentCar);

class Car {

private:
	float vel;
	float pos;
	float comfort_distance;
	int myLane;
public:

	// car constructing 
	Car(float velocity, float dis, int lane)
	{
		vel = velocity;
		comfort_distance = dis;
		myLane = lane;
	}

	//setters and getters
	void setPos(float position) { pos = position; }
	float getPos() { return pos; }

	void setLane(int Setlane) { myLane = Setlane; }
	int getLane() { return myLane; }

	float getDistance() { return comfort_distance; }

	// print me for cars
	void printMe() {
		//cout << "I am velocity: " << vel << endl;
		cout << "position: " << pos << endl;
		cout << "I am in lane: " << myLane << endl;
		//cout << "I am comfort_distance: " << comfort_distance << endl;
		//cout << "" << endl;
	}

	// move cars along the road
	void move(float time, Car* car_ahead, Car* currentcar, Car** allcars) {

		if (car_ahead == NULL) {
			pos = pos + (vel * time);
		}
		else
		{
			if ((currentcar->checker(time) + currentcar->getDistance() > car_ahead->getPos()) == true
				&&
				!(car_difLane(allcars, currentcar))) {

				pos = car_ahead->getPos() - comfort_distance;
			}
			else
			{
				if (currentcar->checker(time) + currentcar->getDistance() > car_ahead->getPos() == false){
				pos = pos + (vel * time);
				}
				else {
					switch (currentcar->getLane()) {
					case 1:
						currentcar->setLane(2);
						pos = pos + (vel * time);
						break;

					case 2:
						currentcar->setLane(1);
						pos = pos + (vel * time);
						break;
					default:
						break;
					}
				}
				
			}
		}
	}

	float checker(float time) { return (pos + (vel * time)); }

};

// essential forward declaration
Car* car_ahead(Car** allCars, Car* currentCar);  

// to find car ahead of chosen car
Car* car_ahead(Car** allCars, Car* currentCar) {

	
	float closest_distance = 100000.0;
	Car* temp = NULL;

	for (int element = 0; element < total_cars; element++) {

		if (allCars[element]->getLane() == currentCar->getLane()) {

			if (currentCar->getPos() - allCars[element]->getPos() < 0.0      &&
				abs(currentCar->getPos() - allCars[element]->getPos()) < closest_distance)
			{
				temp = allCars[element];
				closest_distance = abs(currentCar->getPos() - allCars[element]->getPos());
			}
		}

	}
	return temp; 
}
bool car_difLane(Car** allcars, Car* currentCar) {

	int L = currentCar->getLane();
	bool space_available = false;
	float closest_distance = 100000.0;
	Car* temp = NULL;

	switch (L) {
	case 1: 
		for (int element = 0; element < total_cars; element++) {
			if (allcars[element]->getLane() == 2) {
				if (currentCar->getPos() - allcars[element]->getPos() < 0.0      &&
					abs(currentCar->getPos() - allcars[element]->getPos()) < closest_distance)
				{
					temp = allcars[element];
					closest_distance = abs(currentCar->getPos() - allcars[element]->getPos());
				}
			}
			}
		break;
	case 2:
		for (int element = 0; element < total_cars; element++) {
			if (allcars[element]->getLane() == 1) {
				if (currentCar->getPos() - allcars[element]->getPos() < 0.0      &&
					abs(currentCar->getPos() - allcars[element]->getPos()) < closest_distance)
				{
					temp = allcars[element];
					closest_distance = abs(currentCar->getPos() - allcars[element]->getPos());
				}
			}
		}

		break;
	default:
		break;
	}

	if (temp == NULL) {
		space_available = true;
	}
	else
	{
		if (currentCar->getPos() + currentCar->getDistance() > temp->getPos()) {
			space_available = false;
		}
		else
		{
			space_available = true;
		}
	}

	return space_available;
}

