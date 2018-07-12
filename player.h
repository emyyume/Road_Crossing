#pragma once
#include "obstacle-course/vehicle.h"
#include "obstacle-course/animal.h"

class Player {
public:
	Player();
	void Display() const;
	void Clear() const;
	void Up();
	void Down();
	void Left();
	void Right();
	bool Impact(const Vehicle &vehicle);
	void EditPlayerName(const string &new_name);
	string GetName() const;
private:
	int _x, _y;
	bool _alive;
	string _name;
};