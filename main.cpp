#include "game.h"

int main() {
	try {
		Game game;
		while (true) {
			Console::MainMenu();
			switch (Console::ProcessMainMenu()) {
			case 0://Done
				if (game.Exit()) {
					game.SaveGame();
					return EXIT_SUCCESS;
				}
				else continue;
			case 1://Editing
				if (game.NewGame()) {
					game.StartGame();
				}
				else continue;
				break;
			case 2://Done
				game.LoadGame();
				break;
			case 3://Done
				game.Setting();
				break;
			default: return EXIT_FAILURE;
			}
		}
	}
	catch (...) {
		return EXIT_FAILURE;
	}
}