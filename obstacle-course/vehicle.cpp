#include "vehicle.h"

Vehicle::Vehicle(const int &x):_x(x), _y(18){}
Vehicle::Vehicle(const int &x, const int &y) :_x(x), _y(y) {}

void Vehicle::Move(const int &level) {
	int speed = 0;
	switch (level) {
	case 1: speed = 1000; break;
	case 2: speed = 900; break;
	case 3: speed = 800; break;
	case 4: speed = 700; break;
	case 5: speed = 600; break;
	case 6: speed = 500; break;
	case 7: speed = 400; break;
	case 8: speed = 300; break;
	case 9: speed = 200; break;
	case 10: speed = 100; break;
	default: speed = 1000;
	}
	Sleep(speed);
}
