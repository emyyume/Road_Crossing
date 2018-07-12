#include "player.h"

Player::Player() : _x(60), _y(25), _alive(true) {
	this->Display();
}

void Player::Display() const {
	Console::GotoXY(this->_x, this->_y), cout << (char)220;
	Console::GotoXY(this->_x, this->_y + 1), cout << (char)94;
}
void Player::Clear() const {
	Console::GotoXY(this->_x, this->_y), cout << " ";
	Console::GotoXY(this->_x, this->_y + 1), cout << " ";
}
void Player::Up() {
	this->Clear();
	if ((this->_y - 1 == 24) || (this->_y - 1 == 19) || (this->_y - 1 == 14) || (this->_y - 1 == 9) || (this->_y - 1 == 4))
		this->_y -= 3;
	else if (this->_y > 0)
		--this->_y;
	this->Display();
}
void Player::Down() {
	this->Clear();
	if ((this->_y + 2 == 24) || (this->_y + 2 == 19) || (this->_y + 2 == 14) || (this->_y + 2 == 9) || (this->_y + 2 == 4))
		this->_y += 3;
	else if (this->_y <= 25)
		++this->_y;
	this->Display();
}
void Player::Left() {
	this->Clear();
	if (this->_x > 1)
		--this->_x;
	this->Display();
}
void Player::Right() {
	this->Clear();
	if (this->_x <= 118)
		++this->_x;
	this->Display();
}
bool Player::Impact(const Vehicle &vehicle) {
	return vehicle.Impact(this->_x, this->_y) || vehicle.Impact(this->_x, this->_y + 1);
}
void Player::EditPlayerName(const string &new_name) {
	this->_name = new_name;
}
string Player::GetName() const {
	return this->_name;
}