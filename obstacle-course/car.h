#pragma once
#include "vehicle.h"

class Car :public Vehicle {
public:
	Car() = default;
	Car(const int &x);
	Car(const int &x, const int &y);
	void Display() const;
	void Clear() const;
	void Move();
	bool Impact(const int &x, const int &y) const;
private:

};