#include "bird.h"

Bird::Bird(const int &x) : Animal(x, 6) {}
Bird::Bird(const int &x, const int &y) : Animal(x, y) {}

void Bird::Display() const {
	Console::GotoXY(this->_x, this->_y), cout << (char)223 << (char)223 << (char)220 << (char)223 << (char)223;
}
void Bird::Clear() const {
	Console::GotoXY(this->_x, this->_y), cout << "     ";
}
void Bird::Move() {
	this->Display();
	Sleep(500);
	this->Clear();
	this->_x -= 5;
	this->Display();
}
bool Bird::Impact(const int &x, const int &y) const {
	if (y == this->_y)
		if (x == this->_x || x == this->_x + 1 || x == this->_x + 2 || x == this->_x + 3 || x == this->_x + 4)
			return true;
	return false;
}