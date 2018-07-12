#include "truck.h"

Truck::Truck(const int &x) : Vehicle(x, 23) {
	this->Display();
}
Truck::Truck(const int &x, const int &y) : Vehicle(x, y) {
	this->Display();
}

void Truck::Display() const {
	char block = (char)219;
	Console::GotoXY(this->_x, this->_y);
	for (int i = 0; i < 6; ++i)
		cout << block;

	Console::GotoXY(this->_x + 2, this->_y - 1);
	for (int i = 0; i < 4; ++i)
		cout << block;
}
void Truck::Clear() const {
	Console::GotoXY(this->_x, this->_y), cout << "      ";
	Console::GotoXY(this->_x + 2, this->_y - 1), cout << "    ";
}
void Truck::Move(const int &level) {
	Vehicle::Move(level);
	this->Clear();
	if (this->_x > 0)
		this->_x -= 3;
	if (this->_x < 3) {
		this->Clear();
		this->_x = 114;
	}
	this->Display();
}

bool Truck::Impact(const int &x, const int &y) const {
	if (y == this->_y)
		if (x == this->_x || x == this->_x + 1 || x == this->_x + 2 || x == this->_x + 3 || x == this->_x + 4 || x == this->_x + 5)
			return true;
	if (y == this->_y - 1)
		if (x == this->_x + 2 || x == this->_x + 3 || x == this->_x + 4 || x == this->_x + 5)
			return true;
	return false;
}