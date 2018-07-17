#pragma once
#pragma comment(lib, "Winmm.lib")
#include "../console.h"
#include <mmsystem.h>

class Animal {
public:
	Animal() = default;
	Animal(const int &x, const int &y);
	virtual void Display() const = 0;
	virtual void Remove() const = 0;
	virtual void Move(const int &level);
	virtual bool Impact(const int &x, const int &y) const = 0;
protected:
	int _x, _y;
};