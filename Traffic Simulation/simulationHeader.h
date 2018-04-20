
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <list>

using namespace std;

float bellCurve(float mean, float deviation);

class Car {

private:
	float vel;
	float pos;
	float comfort_distance;
public:
	//static Car* mycars[500];
	//Car() {};                      // default constructor
	Car(float velocity, float dis) // constructor to set vel and dis 
	{ 
		vel = velocity;
		comfort_distance = dis;
	}
	static void arrayAccesser(Car* mycar) {
		
		mycar->printMe();
	};
	void setPos(float position) { pos = position; }
	float getPos() { return pos; }

	//void setDistance(float dis) { comfort_distance = dis; }
	float getDistance() { return comfort_distance; }

	void printMe() {
		cout << "I am velocity: " << vel << endl;
		cout << "position: " << pos << endl;	
		cout << "I am comfort_distance: " << comfort_distance << endl;
		cout << "" << endl;
	}
	void move(float front, float time) { 
		
		if (front < (checker(time) + comfort_distance))
			pos = front - comfort_distance;
		else
			pos = pos + (vel * time); 

	}

	float checker(float time) { return (pos + (vel * time)); }

};
