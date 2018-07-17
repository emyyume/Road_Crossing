#pragma once
#include "vehicle.h"

class Truck :public Vehicle {
public:
	Truck() = default;
	Truck(const int &x);
	void Display() const;
	void Remove() const;
	void Move(const int &level);
	bool Impact(const int &x, const int &y) const;
};