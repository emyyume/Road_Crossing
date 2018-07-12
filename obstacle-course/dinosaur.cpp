#include "dinosaur.h"

Dinosaur::Dinosaur(const int &x) :Animal(x, 13) {}
Dinosaur::Dinosaur(const int &x, const int &y) : Animal(x, y) {}

void Dinosaur::Display() const {
	char block = (char)219;
	Console::GotoXY(this->_x, this->_y);
	for (int i = 0; i < 4; ++i)
		cout << block;

	Console::GotoXY(this->_x - 1, this->_y - 1);
	for (int i = 0; i < 3; ++i)
		cout << block;

	Console::GotoXY(this->_x - 1, this->_y - 2);
	for (int i = 0; i < 2; ++i)
			cout << block;
}
void Dinosaur::Clear() const {
	Console::GotoXY(this->_x, this->_y), cout << "    ";
	Console::GotoXY(this->_x - 1, this->_y - 1), cout << "   ";
	Console::GotoXY(this->_x - 1, this->_y - 2), cout << ' ';
}
void Dinosaur::Move() {
	this->Display();
	Sleep(500);
	this->Clear();
	this->_x -= 5;
	this->Display();
}
bool Dinosaur::Impact(const int &x, const int &y) const {
	if (y == this->_y)
		if (x == this->_x || x == this->_x + 1 || x == this->_x + 2 || x == this->_x + 3)
			return true;
	if (y == this->_y - 1)
		if (x == this->_x - 1 || x == this->_x || x == this->_x + 1)
			return true;
	if (y == this->_y - 2)
		if (x == this->_x - 1 || x == this->_x)
			return true;
	return false;
}