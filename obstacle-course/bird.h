#pragma once
#include "animal.h"

class Bird :public Animal {
public:
	Bird() = default;
	Bird(const int &x);
	Bird(const int &x, const int &y);
	void Display() const;
	void Clear() const;
	void Move();
	bool Impact(const int &x, const int &y) const;
private:

};