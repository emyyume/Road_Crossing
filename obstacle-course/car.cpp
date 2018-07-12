#include "car.h"

Car::Car(const int &x) :Vehicle(x, 18) {}
Car::Car(const int &x, const int &y) :Vehicle(x, y) {}

void Car::Display() const {
	char block = (char)219;
	Console::GotoXY(this->_x, this->_y);
	for (int i = 0; i < 6; ++i)
		cout << block;

	Console::GotoXY(this->_x + 1, this->_y - 1);
	for (int i = 0; i < 4; ++i)
		cout << block;
}
void Car::Clear() const {
	Console::GotoXY(this->_x, this->_y), cout << "      ";
	Console::GotoXY(this->_x + 1, this->_y - 1), cout << "    ";
}
void Car::Move() {
	this->Display();
	Sleep(500);
	this->Clear();
	this->_x -= 5;
	this->Display();
}
bool Car::Impact(const int &x, const int &y) const {
	if (y == this->_y)
		if (x == this->_x || x == this->_x + 1 || x == this->_x + 2 || x == this->_x + 3 || x == this->_x + 4 || x == this->_x + 5)
			return true;
	if (y == this->_y - 1)
		if (x == this->_x + 1 || x == this->_x + 2 || x == this->_x + 3 || x == this->_x + 4)
			return true;
	return false;
}