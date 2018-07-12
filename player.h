#pragma once
#include "obstacle-course/vehicle.h"
#include "obstacle-course/animal.h"

class Player {
public:
	Player() = default;
	Player(const int &x, const int &y);
	void Display() const;
	void Clear() const;
	void Up();
	void Down();
	void Left();
	void Right();
	bool Impact(const Vehicle* &vehicle);
	bool Impact(const Animal* &animal);
private:
	int _x, _y;
	bool _alive;
};