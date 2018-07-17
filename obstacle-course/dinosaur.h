#pragma once
#include "animal.h"

class Dinosaur :public Animal {
public:
	Dinosaur() = default;
	Dinosaur(const int &x);
	void Display() const;
	void Remove() const;
	void Move(const int &level);
	bool Impact(const int &x, const int &y) const;
};