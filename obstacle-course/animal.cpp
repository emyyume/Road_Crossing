#include "animal.h"

Animal::Animal(const int &x, const int &y) :_x(x), _y(y) {}

void Animal::Move(const int &level) {
	switch (level) {
	case 1: Sleep(10); break;
	case 2: Sleep(9); break;
	case 3: Sleep(8); break;
	case 4: Sleep(7); break;
	case 5: Sleep(6); break;
	case 6: Sleep(5); break;
	case 7: Sleep(4); break;
	case 8: Sleep(3); break;
	case 9: Sleep(2); break;
	case 10: Sleep(1); break;
	}
}