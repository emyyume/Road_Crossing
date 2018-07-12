#include "game.h"

void Game::EachDataSaved(ifstream &fin, const int &number) const {
	int x = 0, y = 0;
	switch (number) {
	case 1: x = 34, y = 7; break;
	case 2: x = 68, y = 7; break;
	case 3: x = 34, y = 13; break;
	case 4: x = 68, y = 13; break;
	case 5: x = 34, y = 19; break;
	case 6: x = 68, y = 19; break;
	}
	string player_name;
	int level;
	if (!fin.is_open())
		Console::GotoXY(x, y), cout << "No data";
	else {
		getline(fin, player_name);
		fin >> level;
		Console::GotoXY(x, y), cout << "Name: " << player_name;
		Console::GotoXY(x, y + 1), cout << "Level: " << level;
	}
	fin.close();
}
void Game::PrintSaveData() const {
	ifstream fin("save/save1.txt");
	this->EachDataSaved(fin, 1);

	fin.open("save/save2.txt");
	this->EachDataSaved(fin, 2);

	fin.open("save/save3.txt");
	this->EachDataSaved(fin, 3);

	fin.open("save/save4.txt");
	this->EachDataSaved(fin, 4);

	fin.open("save/save5.txt");
	this->EachDataSaved(fin, 5);

	fin.open("save/save6.txt");
	this->EachDataSaved(fin, 6);
}
void Game::LoadData(const int &number) {
	ifstream fin;
	switch (number) {
	case 1: fin.open("save/save1.txt"); break;
	case 2: fin.open("save/save2.txt"); break;
	case 3: fin.open("save/save3.txt"); break;
	case 4: fin.open("save/save4.txt"); break;
	case 5: fin.open("save/save5.txt"); break;
	case 6: fin.open("save/save6.txt"); break;
	}
	if (fin.is_open()) {
		string player_name;
		int level;
		getline(fin, player_name);
		fin >> level;
		this->_player->EditPlayerName(player_name);
		this->_level = level;
	}
	else {
		string text = "Error: This is empty.";
		Console::SetText(text, 60 - text.length() / 2, 2);
		_getwch(); this->LoadGame();
	}
	fin.close();
}
void Game::SaveData(const int &number) {
	ofstream fout;
	switch (number) {
	case 1: fout.open("save/save1.txt"); break;
	case 2: fout.open("save/save2.txt"); break;
	case 3: fout.open("save/save3.txt"); break;
	case 4: fout.open("save/save4.txt"); break;
	case 5: fout.open("save/save5.txt"); break;
	case 6: fout.open("save/save6.txt"); break;
	}
	if (fout.is_open())
		fout << this->_player->GetName() << endl << this->_level;
	else {
		string text = "Error: Can't save the game data. Make sure in this directory has a folder \"save\".";
		Console::SetText(text, 60 - text.length() / 2, 2);
		_getwch(); this->SaveGame();
	}
	fout.close();
}

Game::Game() : STOP(false), _player(new Player), _level(1) {
	Console::ShowConsoleCursor(false);
}
Game::~Game() {
	this->STOP = true;
	this->_level = 0;
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
	this->DrawMap();

	_getwch();
}

bool Game::NewGame() {
	system("cls");
	Console::NewGameMenu();

	Console::Choose(31, 6);
	Console::GotoXY(54, 6);
	string player_name; getline(cin, player_name);

	if (Console::Accept()) {
		this->_player->EditPlayerName(player_name);
		return true;
	}
	else return false;
}
void Game::SaveGame() {
	system("cls");
	Console::SaveGameMenu();
	this->PrintSaveData();

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
		switch (y) {
		case 7:
			if (x == 30) this->SaveData(1);
			else if (x == 64) this->SaveData(2);
			break;
		case 13:
			if (x == 30) this->SaveData(3);
			else if (x == 64) this->SaveData(4);
			break;
		case 19:
			if (x == 30) this->SaveData(5);
			else if (x == 64) this->SaveData(6);
			break;
		}
	}
}
void Game::LoadGame() {
	system("cls");
	Console::LoadGameMenu();
	this->PrintSaveData();

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
		switch (y) {
		case 7:
			if (x == 30) this->LoadData(1);
			else if (x == 64) this->LoadData(2);
			break;
		case 13:
			if (x == 30) this->LoadData(3);
			else if (x == 64) this->LoadData(4);
			break;
		case 19:
			if (x == 30) this->LoadData(5);
			else if (x == 64) this->LoadData(6);
			break;
		}
	}
}
void Game::Setting() {
	system("cls");
	Console::SettingMenu();
	
	Console::Choose(31, 6);
	Console::GotoXY(54, 6);
	string player_name; getline(cin, player_name);

	Console::GotoXY(31, 6), cout << ' ', Console::Choose(31, 10);
	Console::GotoXY(54, 10);
	int level = 0; cin >> level, cin.get();
	if (cin.fail()) return;

	if (Console::Accept()) {
		this->_player->EditPlayerName(player_name);
		level = (level > 0) ? level : -level;
		if (level <= this->_level)
			this->_level = level;
		else {
			string text = "Error: Can't change to this level.";
			Console::SetText(text, 60 - text.length() / 2, 2);
			_getwch(); this->Setting();
		}
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
bool Game::GameOver() {
	system("cls");
	Console::GameOverMenu();

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

void Game::AllMove() {

}
void Game::Stop(thread* sub_thread) {
	system("cls");
	this->STOP = true;
	sub_thread->join();
}
