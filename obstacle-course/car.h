#pragma once
#include "vehicle.h"

class Car :public Vehicle {
public:
	Car() = default;
	Car(const int &x);
	void Display() const;
	void Remove() const;
	void Move(const int &level);
	bool Impact(const int &x, const int &y) const;
};