/* #include <iostream>
#include <string>
#include <stdlib.h>
#include "simulationHeader.h"
#include <time.h>
#include <windows.h>

using namespace std;

//manualCar road1[1000];
Car * ptr;

int main() {
	Car *track[500];

	//ptr = new manualCar[1000];

	for (int x = 0; x < 500; x++) {

		track[x] = new Car();

	}

	for (int x = 0; x < 500; x++) {

		track[x]->set(bellCurve(), x);   // set function will set ( velocity , position )

	}
	cout << bellCurve() << " this is bellcurve " << endl;

	cout << bellCurve() << " bell curve redone " << endl;

	//ptr->printMe;

	//ptr = &track[0];
	//string k = track[1].printMe();
	cout << track[1]->velocity << endl;
	cout << track[1]->position << endl;

	cout << track[1]->printMe() << endl;



	//road1[5] = new manualCar(4, 8);

	//*ptr = road1[5];



	//for (int x = 0; x < 999; x++) {
	//road1[x] = x;
	//}
	//cout << ptr->printMe << endl;
	system("pause");
	return 0;

}
int bellCurve() {

	Sleep(80);
	srand((unsigned)time(0));
	int ran = 1 + (rand() % 100);
	return ran;

} */