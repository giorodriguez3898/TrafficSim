/* #pragma once
#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

int bellCurve();

class Car {

public:
	int velocity;
	int position;

	Car() { velocity = 0; position = 0; };

	void set(int vel, int pos) {
		velocity = vel;
		position = pos;
	}
	string printMe() {

		string k = "I am velocity " + velocity;
		string j = "I am position " + position;

		return k.append(j);
	}


}; */