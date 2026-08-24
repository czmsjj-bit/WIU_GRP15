#include "Menu.h"
#include <conio.h>   // For _getch()
#include <cstdlib>   // For system("cls")
#include "Inventory.h"

Menu::Menu() {
	persephoneDialogue.AddDialogue("1");
	persephoneDialogue.AddDialogue("2");
	persephoneDialogue.AddDialogue("3");
	persephoneDialogue.AddDialogue("4");
}

void Menu::printTitle() {
	std::cout << "==============================================================================" << std::endl;
	std::cout << "																		" << std::endl;
	std::cout << "	.eeeee.eee..eee.eeeeeee...eeeeee.eeeeee.....eeeeee..eeeeee.			" << std::endl;
	std::cout << "	@@@@@@:@@@::@@@:@@@@@@@@:@@@@@@@:@@@@@@::::@@@@@@@@:@@@@@@:			" << std::endl;
	std::cout << "	%%%----%%%--%%%-%%%--%%%-%%%-----%%%-------%%%--%%%-%%%----			" << std::endl;
	std::cout << "	&&&++++&&&++&&&+&&&&&&&++&&&&&&++&&&&&+++++&&&++&&&+&&&&&++			" << std::endl;
	std::cout << "	|||****|||**|||*||||||****||||||*|||||*****|||**|||*|||||**			" << std::endl;
	std::cout << "	!!!====!!!==!!!=!!!=!!!======!!!=!!!=======!!!==!!!=!!!====			" << std::endl;
	std::cout << "	::::::#::::::::#:::##:::#:::::::#::::::####::::::::#:::####			" << std::endl;
	std::cout << "	@.....@@......@@...@@...@......@@......@@@@@......@@...@@@@			" << std::endl;
	std::cout << "																		" << std::endl;
	std::cout << "	.eeeeee.eee..eeeeee.eee...eee.eeeeeee..eee..eee.eee..eee..eeeeee.	" << std::endl;
	std::cout << "	@@@@@@@:@@@:@@@@@@@:@@@:::@@@.@@@@@@@@:@@@::@@@:@@@::@@@:@@@@@@@:	" << std::endl;
	std::cout << "	%%%-----%%%-%%%-----%%%---%%%-%%%--%%%-%%%--%%%-%%%--%%%-%%%-----	" << std::endl;
	std::cout << "	&&&&&&++&&&+&&&&&&+++&&&&&&&++&&&&&&&&+&&&&&&&&+&&&++&&&+&&&&&&++	" << std::endl;
	std::cout << "	*||||||*|||**||||||***|||||***|||||||**||||||||*|||**|||**||||||*	" << std::endl;
	std::cout << "	====!!!=!!!=====!!!====!!!====!!!======!!!==!!!=!!!==!!!=====!!!=	" << std::endl;
	std::cout << "	:::::::#:::#:::::::####:::####:::######:::##:::#::::::::#:::::::#	" << std::endl;
	std::cout << "	......@@...@......@@@@@...@@@@...@@@@@@...@@...@@......@@......@@	" << std::endl;
	std::cout << "																		" << std::endl;
	std::cout << "==============================================================================" << std::endl;
	std::cout << "																		" << std::endl;
	std::cout << "Press 'Enter' to start the game." << std::endl;
	std::cout << "Press 0 to view game controls." << std::endl;
}

void Menu::showTitleScreen() {
	printTitle();
	char input = _getch(); // Wait for key press

	switch (input) {

	case '\r': // Enter key
		system("cls");
		showGameScreen();
		break;

	case '0':
		system("cls");
		showControls();
		break;

	default:
		system("cls");
		std::cout << "Invalid choice. Try again.\n";
		break;
	}
}

void Menu::showControls() {
	while (true) {
		system("cls");

		std::cout << "==============================================================================" << std::endl;
		std::cout << "				Game Controls" << std::endl;
		std::cout << "==============================================================================" << std::endl;
		std::cout << "																		" << std::endl;
		std::cout << "[u] > Resets current layout of room to starting layout " << std::endl;
		std::cout << "[g] > Allows / Disallows player to push boulder" << std::endl;
		std::cout << "[k] > Moves on to next dialogue line" << std::endl;
		std::cout << "[i] > Opens / Closes player's inventory" << std::endl;
		std::cout << "																		" << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		std::cout << "																		" << std::endl;
		std::cout << "*Press 'l' to return to the game screen.*" << std::endl;

		char input = _getch();

		switch (input) {

		case 'l':
		case 'L':
			return;  // Return to showGameScreen()

		default:
			break;
		}
	}
}

void Menu::showGameScreen() {
	while (true) {
		system("cls");
		std::cout << "==============================================================================" << std::endl;
		std::cout << "				Game Screen" << std::endl;
		std::cout << "==============================================================================" << std::endl;
		std::cout << std::endl;

		std::cout << " [I]  Open Inventory" << std::endl;
		std::cout << " [0]  View Game Controls" << std::endl;
		std::cout << " [K]  Continue Dialogue" << std::endl;

		std::cout << std::endl;
		std::cout << "==============================================================================" << std::endl;

		char input = _getch();

		switch (input) {

		case 'i':
			inventory.RunInventory();
			break;

		case '0':
			showControls();
			break;

		case 'k':
			while (!persephoneDialogue.IsFinished()) {
				persephoneDialogue.DisplayDialogue();
				persephoneDialogue.NextDialogue();
			}
			break;

		default:
			break;
		}
	}
}