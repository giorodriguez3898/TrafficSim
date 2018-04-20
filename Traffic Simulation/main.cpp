#include <iostream>
#include <string>
#include <stdlib.h>
#include "simulationHeader.h"
#include <time.h>
#include <windows.h>
#include <random>

using namespace std;

static float vel_mean = 17.8;
static float vel_dev = 4.0;
static float distance_mean = 4.0;
static float distance_dev = 2.0;
Car **mycars = new Car*[300];


int main() {                       

	mycars[0] = new Car(vel_mean, distance_mean);
	mycars[0]->printMe();

	//Car::arrayAccesser(mycars);


	/*for (int x = 0; x < 300; x++) {
		mycars[x] = new Car( bellCurve(vel_mean, vel_dev), bellCurve(distance_mean, distance_dev) );        
		// constructs cars and sets velocity and sets comfort distance 
	}*/
	

/*	float y = 0.0
	for (int x = 0; x < 300; x++) {

		Car::mycars[x]->setPos(y);
		y =+ 15;
	}

	cout << "about to initiate a print me: " << endl;
	cout << "" << endl;*/

	//Car::mycars[5]->printMe();
	//float vel1 = bellCurve(vel_mean, vel_dev);
	//cout << "this is velocity 1: " << vel1 << endl;
	//Car *car = new Car(vel1);

	//float vel2 = bellCurve(vel_mean, vel_dev);
	//cout << "this is velocity 2: " << vel2 << endl;
	//Car *car2 = new Car(vel2);


	//car->setDistance( bellCurve(distance_mean, distance_dev) );
	//car2->setDistance( bellCurve(distance_mean, distance_dev) );




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