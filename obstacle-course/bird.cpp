#include "bird.h"

Bird::Bird(const int &x) : Animal(x, 6) {}

void Bird::Display() const {
	Console::GotoXY(this->_x, this->_y), cout << (char)223 << (char)223 << (char)220 << (char)223 << (char)223;
}
void Bird::Remove() const {
	Console::GotoXY(this->_x, this->_y), cout << "     ";
}
void Bird::Move(const int &level) {
	Animal::Move(level);
	this->Remove();
	if (this->_x > 115)
		this->_x = 0;
	else ++this->_x;
	this->Display();
}
bool Bird::Impact(const int &x, const int &y) const {
	if (y == this->_y)
		if (x == this->_x || x == this->_x + 1 || x == this->_x + 2 || x == this->_x + 3 || x == this->_x + 4)
			return true;
	return false;
}