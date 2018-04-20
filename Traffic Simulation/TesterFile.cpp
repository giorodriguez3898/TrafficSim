#include <iostream>

using namespace std;

int road[100];


int main() {

	cout << "im in " << endl;

	Car mycar; 

	int y = 0;
	for (int x = 0; x < 100; x++) {
		
		y = +5;
		road[x] = y;
	}

	mycar.set(4, road[5]);

	mycar.printMe();

	cout << "end of print me" << endl;
	





}


class Car {

public:
	int velocity;
	int *position;

	Car() { velocity = 0; };

	void set(int vel, int myspot) {
		velocity = vel;
		*position = myspot;
		//position = pos;
	}
	void printMe() {


		char vel[20] = "I am velocity ";
		cout << vel << velocity << endl;

		cout << "position without the asterik: " << position << endl;
		cout << "position with the asterik: " << *position << endl;
	}


};