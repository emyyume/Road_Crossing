#pragma once
#include "vehicle.h"

class Truck :public Vehicle {
public:
	Truck() = default;
	Truck(const int &x);
	Truck(const int &x, const int &y);
	void Display() const;
	void Clear() const;
	void Move(const int &level);
	bool Impact(const int &x, const int &y) const;
private:

};