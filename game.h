#pragma once
#include "player.h"
#include "obstacle-course/truck.h"
#include "obstacle-course/car.h"
#include "obstacle-course/dinosaur.h"
#include "obstacle-course/bird.h"
#include <vector>
#include <thread>

class Game {
public:
	Game();
	~Game();
	void DrawMap() const;
	void StartGame();
	bool NewGame();
	void LoadGame();
	void Setting();
	bool Exit();
private:
	Player* _player;
	vector<Vehicle*> _vehicles;
	vector<Animal*> _animals;
	bool STOP;
	int _level;
};