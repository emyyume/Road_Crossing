#include "game.h"

Game::Game() : STOP(false), _player(new Player), _level(1) {}
Game::~Game() {
	this->STOP = true;
	if (this->_player)
		delete this->_player;
	for (auto &i : this->_vehicles)
		delete i;
	for (auto &i : this->_animals)
		delete i;
}

void Game::DrawMap() const {
	char line = (char)196;
	for (int i = 0; i < 120; ++i)
		Console::GotoXY(i, 4), cout << line,
		Console::GotoXY(i, 9), cout << line,
		Console::GotoXY(i, 14), cout << line,
		Console::GotoXY(i, 19), cout << line,
		Console::GotoXY(i, 24), cout << line;
}
void Game::StartGame() {
	system("cls");
	cout << "Start Game";
	_getwch();
}

bool Game::NewGame() {
	system("cls");
	Console::NewGameMenu();

	Console::GotoXY(33, 6);
	string player_name; getline(cin, player_name);

	if (Console::Accept()) {
		//
		return true;
	}
	else return false;
}
void Game::LoadGame() {
	system("cls");
	Console::LoadGameMenu();
	
	int x = 30, y = 7;
	Console::Choose(x, y); //Save-data 1

	while (_getch() != 13) {
		if (_kbhit()) {
			char key = _getch();
			switch (key) {
			case 72: //Up
				if (y > 7) {
					Console::GotoXY(x, y); cout << ' ';
					Console::Choose(x, y -= 6);
				}
				break;
			case 80: //Down
				if (y < 19) {
					Console::GotoXY(x, y); cout << ' ';
					Console::Choose(x, y += 6);
				}
				break;
			case 75: //Left
				if (x == 64) {
					Console::GotoXY(x, y); cout << ' ';
					Console::Choose(x -= 34, y);
				}
				break;
			case 77: //Right
				if (x == 30) {
					Console::GotoXY(x, y); cout << ' ';
					Console::Choose(x += 34, y);
				}
				break;
			}
		}
	}

	if (Console::Accept()) {
		//load data
	}
}
void Game::Setting() {
	system("cls");
	Console::SettingMenu();
	
	Console::GotoXY(33, 6);
	string player_name; getline(cin, player_name);

	if (Console::Accept()) {
		//
	}
}
bool Game::Exit() {
	system("cls");
	Console::ExitMenu();
	
	int x = 45;
	Console::Choose(x, 15);

	while (_getch() != 13) {
		if (_kbhit()) {
			char key = _getch();
			switch (key) {
			case 75:
				if (x == 59) {
					Console::GotoXY(x, 15); cout << ' ';
					Console::Choose(x -= 14, 15);
				}
				break;
			case 77:
				if (x == 45) {
					Console::GotoXY(x, 15); cout << ' ';
					Console::Choose(x += 14, 15);
				}
			}
		}
	}

	return x == 59;
}