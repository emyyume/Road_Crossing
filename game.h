#pragma once
#include "player.h"
#include "obstacle-course/truck.h"
#include "obstacle-course/car.h"
#include "obstacle-course/dinosaur.h"
#include "obstacle-course/bird.h"
#include <vector>
#include <thread>
#include <fstream>
#include <mutex>

class Game {
public:
	Game();
	~Game();
	void DrawMap() const;
	void StartGame();
	bool NewGame();
	void SaveGame();
	void LoadGame();
	void Setting();
	bool Exit();
	bool Win();
	bool GameOver();
	void ResetGame();
	void AllMove(const int &level);
	void Stop(thread* sub_thread);
private:
	Player* _player;
	vector<Vehicle*> _vehicles;
	vector<Animal*> _animals;
	bool STOP;
	int _level;
	mutex _mutex;
	void EachDataSaved(ifstream &fin, const int &number) const;
	void PrintSaveData() const;
	void LoadData(const int &number);
	void SaveData(const int &number);
};