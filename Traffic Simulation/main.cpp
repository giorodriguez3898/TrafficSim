#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "simulationHeader.h"
#include <time.h>
#include <windows.h>
#include <random>
#include <cmath>

using namespace std;

// setting my array of cars
Car **mycars = new Car*[total_cars];
int main() {                       


	// to keep track of how many cars are left to be instantiated
	int auto_reduce = number_of_auton;               
	int manual_reduce = number_of_manual;           
	bool mySwitch = false;

	// instantiates autonomous && manual cars by alternating 
	for (int element = 0; element < total_cars; element++) {

		if (!(auto_reduce == 0) && (mySwitch == false)) {
			mycars[element] = new Car(bellCurve(vel_mean, AutonVel_dev), 
								bellCurve(distance_mean, autonDistance_dev), 
								uniformNumber(lane_min, lane_max) );
			auto_reduce--;

			if (!(manual_reduce == 0)) {
				mySwitch = true;
			}
		}
		else if( !(manual_reduce == 0) && (mySwitch == true) ){
			mycars[element] = new Car(bellCurve(vel_mean, Manualvel_dev), 
								bellCurve(distance_mean, Manualdistance_dev),
								uniformNumber(lane_min, lane_max) );
			manual_reduce--;

			if (!(auto_reduce == 0)) {
				mySwitch = false;
			}
		}
	}

	// places cars randomly at a position between 25 meters and 125 meters
	for (int element = 0; element < total_cars; element++) {
		mycars[element]->setPos(uniformNumber(position_min, position_max));
	}


	for (float time = 0; time < seconds_for_simulation; time = time + 1.0) {

		cout << "" << endl;
		cout << "Stats for time #" << time << endl;
		

		for (int element = 0; element < total_cars; element++) {

			cout << "car number [" << element << "]" << endl;
			mycars[element]->move(
									time, 
									car_ahead(mycars, mycars[element]), 
									mycars[element],
									mycars
								);
			mycars[element]->printMe();
		}

	}

	float tracker = 0.0;
	for (int x = 0; x < total_cars; x++) {
		

		if (mycars[x]->getPos() > 7800.0) {
			tracker++;
		}
	}
	float percentage = tracker / total_cars;

	cout << "Percentage of cars that made it through: " << percentage << "%" << endl;

	system("pause");

}
float bellCurve(float mean, float deviation) {

	Sleep(80);
	time_t t = clock();
	default_random_engine generator(t);
	normal_distribution<float> distribution(mean, deviation);
	float number = distribution(generator);

	return number;

}
float uniformNumber(float minimum, float maximum) {

	Sleep(80);
	time_t t = clock();
	std::default_random_engine generator(t);
	std::uniform_real_distribution<double> distribution(minimum, maximum);

	float b = distribution(generator);
	return b;
}