#include "game.h"

int main() {
	try {
		Game game;
		while (true) {
			Console::MainMenu();
			switch (Console::ProcessMainMenu()) {
			case 0:
				if (game.Exit()) return EXIT_SUCCESS;
				else continue;
			case 1:
				if (game.NewGame()) {
					game.StartGame();
				}
				else continue;
				break;//
			case 2:
				game.LoadGame();
				break;
			case 3:
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