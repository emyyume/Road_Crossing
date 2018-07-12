#pragma once
#include "../console.h"

class Animal {
public:
	Animal() = default;
	Animal(const int &x);
	Animal(const int &x, const int &y);
	virtual void Display() const = 0;
	virtual void Clear() const = 0;
	virtual void Move() = 0;
	virtual bool Impact(const int &x, const int &y) const = 0;
protected:
	int _x, _y;
};