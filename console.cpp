#include "console.h"

void Console::FixConsoleWindow() {
	HWND console_window = GetConsoleWindow();
	LONG style = GetWindowLong(console_window, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(console_window, GWL_STYLE, style);
}
void Console::ShowConsoleCursor(const bool &choose) {
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	cursor.bVisible = choose;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void Console::GotoXY(const int &x, const int &y) {
	if (x < 0 || x > 129 || y < 0 || y > 29)
		return;
	COORD coord;
	coord.X = x, coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Console::SetText(const string &text, const int &x, const int &y) {
	GotoXY(x, y), cout << text;
}
void Console::Choose(const int &x, const int &y) {
	GotoXY(x, y); cout << (char)175;
}
void Console::Border(const int &width, const int &height, const int &x, const int &y) {
	if (width < 1 || height < 1 || x < 0 || y < 0 || x > 129 || y > 29)
		return;

	GotoXY(x, y); cout << (char)218;
	for (int i = 0; i < width; ++i)
		cout << (char)196;
	cout << (char)191;

	for (int i = 0; i < height; ++i) {
		GotoXY(x, y + i + 1); cout << (char)179;
		GotoXY(x + width + 1, y + i + 1); cout << (char)179;
	}

	GotoXY(x, y + height + 1); cout << (char)192;
	for (int i = 0; i < width; ++i)
		cout << (char)196;
	cout << (char)217;
}
void Console::Button(const string &text, const int &width, const int &height, const int &x, const int &y) {
	Border(width, height, x, y);

	int text_length = text.length();
	if (text_length > width || height % 2 == 0)
		return;

	GotoXY((width - text_length) / 2 + x + 1, height / 2 + y + 1); cout << text;
}

void Console::MainMenu() {
	system("cls");
	SetConsoleTitle("Road Crossing");

	GotoXY(38, 0); cout << "  ________";
	GotoXY(38, 1); cout << " /  ____  \\                               __";
	GotoXY(38, 2); cout << "/  /    \\  \\                             |  |";
	GotoXY(38, 3); cout << "|  \\____/  /                             |  |";
	GotoXY(38, 4); cout << "|   ___   /     _____     ______      ___|  |";
	GotoXY(38, 5); cout << "|  |   \\  \\    /  _  \\   /  _   \\    /  _   |";
	GotoXY(38, 6); cout << "|  |    \\  \\  |  |_|  | |  |_|   \\  |  |_|  |";
	GotoXY(38, 7); cout << "|__|     \\__\\  \\_____/   \\_____/\\_\\  \\_____/";
	GotoXY(25, 8); cout << "   ________";
	GotoXY(25, 9); cout << "  /  ____  \\";
	GotoXY(25, 10); cout << " /  /    \\__\\                                    _";
	GotoXY(25, 11); cout << "|  |                                            |_|";
	GotoXY(25, 12); cout << "|  |           ______    _____     ____   ____   _    ______    _____";
	GotoXY(25, 13); cout << "|  |      ___ /   ___\\  /  _  \\   /  __| /  __| / \\  /  __  \\  /  _  \\";
	GotoXY(25, 14); cout << " \\  \\____/  / |  |     |  |_|  | _\\  \\  _\\  \\   | |  | |  | | |  |_|  |";
	GotoXY(25, 15); cout << "  \\________/  \\__/      \\_____/ |____/ |____/   \\_/  |_|  |_|  \\___   |";
	GotoXY(25, 16); cout << "                                                               ___ |  |";
	GotoXY(25, 17); cout << "                                                               \\  \\/  |";
	GotoXY(25, 18); cout << "                                                                \\____/";

	Button("NEW GAME", 40, 1, 40, 17);
	Button("LOAD GAME", 40, 1, 40, 20);
	Button("SETTING", 40, 1, 40, 23);
	Button("EXIT", 40, 1, 40, 26);
}
int Console::ProcessMainMenu() {
	int y = 18;
	Choose(38, y); //New Game

	while (_getch() != 13) {
		if (_kbhit()) {
			char key = _getch();
			switch (key) {
			case 80: //Go down
				if (y < 27) {
					GotoXY(38, y); cout << ' ';
					Choose(38, y += 3);
				}
				break;
			case 72: //Go up
				if (y > 18) {
					GotoXY(38, y); cout << ' ';
					Choose(38, y -= 3);
				}
				break;
			}
		}
	}

	switch (y) {
	case 18: //New Game
		return 1;
	case 27: //Exit
		return 0;
	case 21: //Load Game
		return 2;
	case 24: //Setting
		return 3;
		break;
	default: return 0;
	}
}
void Console::NewGameMenu() {
	Border(60, 20, 29, 4);

	string text = "New Game";
	SetText(text, 60 - text.length() / 2, 2);

	SetText("Player Names:", 33, 6);
	Border(32, 1, 53, 5);

	Button("Back", 10, 1, 32, 22);
	Button("GO", 10, 1, 76, 22);
}
void Console::LoadGameMenu() {
	Border(60, 20, 29, 4);

	string text = "Load Game";
	SetText(text, 60 - text.length() / 2, 2);

	Border(20, 3, 32, 5);
	SetText("Save-data 1", 34, 6);
	Border(20, 3, 32, 11);
	SetText("Save-data 3", 34, 12);
	Border(20, 3, 32, 17);
	SetText("Save-data 5", 34, 18);

	Border(20, 3, 66, 5);
	SetText("Save-data 2", 68, 6);
	Border(20, 3, 66, 11);
	SetText("Save-data 4", 68, 12);
	Border(20, 3, 66, 17);
	SetText("Save-data 6", 68, 18);

	Button("Back", 10, 1, 32, 22);
	Button("Load", 10, 1, 76, 22);
}
void Console::SettingMenu() {
	Border(60, 20, 29, 4);

	string text = "Setting";
	SetText(text, 60 - text.length() / 2, 2);

	SetText("New player name:", 33, 6);
	Border(32, 1, 53, 5);

	Button("Back", 10, 1, 32, 22);
	Button("Save", 10, 1, 76, 22);
}
void Console::ExitMenu() {
	Border(30, 5, 44, 12);

	string text = "Do you want to exit?";
	SetText(text, 60 - text.length() / 2, 10);

	Button("Continue", 10, 1, 47, 14);
	Button("Exit", 10, 1, 61, 14);
}
bool Console::Accept() {
	int x = 74;
	Choose(x, 23);

	while (_getch() != 13) {
		if (_kbhit()) {
			char key = _getch();
			switch (key) {
			case 75:
				if (x == 74) {
					GotoXY(x, 23); cout << ' ';
					Choose(x -= 44, 23);
				}
				break;
			case 77:
				if (x == 30) {
					GotoXY(x, 23); cout << ' ';
					Choose(x += 44, 23);
				}
				break;
			}
		}
	}

	return x == 74;
}