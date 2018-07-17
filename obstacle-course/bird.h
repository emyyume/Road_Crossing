#pragma once
#include "animal.h"

class Bird :public Animal {
public:
	Bird() = default;
	Bird(const int &x);
	void Display() const;
	void Remove() const;
	void Move(const int &level);
	bool Impact(const int &x, const int &y) const;
};