#pragma once
#include "animal.h"

class Dinosaur :public Animal {
public:
	Dinosaur() = default;
	Dinosaur(const int &x);
	Dinosaur(const int &x, const int &y);
	void Display() const;
	void Clear() const;
	void Move();
	bool Impact(const int &x, const int &y) const;
private:

};