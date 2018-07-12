#include "player.h"

Player::Player(const int &x, const int &y) : _x(x), _y(y), _alive(true) {}

void Player::Display() const {
	Console::GotoXY(this->_x, this->_y), cout << (char)220;
	Console::GotoXY(this->_x, this->_y + 1), cout << (char)94;
}
void Player::Clear() const {
	Console::GotoXY(this->_x, this->_y), cout << ' ';
	Console::GotoXY(this->_x, this->_y + 1), cout << ' ';
}
void Player::Up() {
	this->Clear();
	if (this->_y >= 0 && this->_y <= 29)
		--this->_y;
	this->Display();
}
void Player::Down() {
	this->Clear();
	if (this->_y >= 0 && this->_y <= 29)
		++this->_y;
	this->Display();
}
void Player::Left() {
	this->Clear();
	if (this->_x >= 0 && this->_x <= 119)
		--this->_x;
	this->Display();
}
void Player::Right() {
	this->Clear();
	if (this->_x >= 0 && this->_x <= 119)
		++this->_x;
	this->Display();
}
bool Player::Impact(const Vehicle* &vehicle) {
	if (vehicle->Impact(this->_x, this->_y) || vehicle->Impact(this->_x, this->_y + 1)) {
		this->_alive = false;
		return true;
	}
	return false;
}
bool Player::Impact(const Animal* &animal) {
	if (animal->Impact(this->_x, this->_y) || animal->Impact(this->_x, this->_y + 1)) {
		this->_alive = false;
		return true;
	}
	return false;
}