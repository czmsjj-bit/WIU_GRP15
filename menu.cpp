#include <conio.h>   // For _getch()
#include <cstdlib>   // For system("cls")

#include "Menu.h"
#include "Inventory.h"
#include "maphandler.h"
//This is format for dialogue, 0 is just the room number
//Add [insert nameDialogue].AddDialogue into 

//playerDialogue.AddDialogue(0, "You - ");
//persephoneDialogue.AddDialogue(0, "Persephone - ");

Menu::Menu(maphandler* handler) {

	mapHandler = handler;
		// Room 1 dialogue
		playerDialogue.AddDialogue(0, "*You wake up after a deep slumber.*");
		persephoneDialogue.AddDialogue(0, "??? - *Hovers around you.*");
		persephoneDialogue.AddDialogue(0, "??? - I am sorry little one.");
		playerDialogue.AddDialogue(0, "You - Where am I?");
		persephoneDialogue.AddDialogue(0, "Persephone - My name is Persephone, wife of Hades, daughter of Demeter. I have to come to undo the injustice that has been done to you, Sosicles.");
		persephoneDialogue.AddDialogue(0, "Persephone - Sosicles, the God of Death, Thanatos has taken you instead of Sisyphus who has insulted the Gods.");
		persephoneDialogue.AddDialogue(0, "Persephone - Your soul was damned for eternal punishment as well.");
		persephoneDialogue.AddDialogue(0, "Persephone - For their hubris had blinded them, you will be in place of Sisyphus' stead before they capture him for fated punishment that his soul deserves.");
		persephoneDialogue.AddDialogue(0, "Persephone - However in good faith, Hades and Thanatos have acknowledged that their mistake and have offered you a way out.");
		persephoneDialogue.AddDialogue(0, "Persephone - Outsmart the trials meant to chain Sisyphus and you shall be free.");
		persephoneDialogue.AddDialogue(0, "Persephone - Quite simple, is it not?");
		persephoneDialogue.AddDialogue(0, "Persephone - Allow me to elaborate a little further.");
		persephoneDialogue.AddDialogue(0, "Persephone - You shall undertake the task of pushing a boulder up a mountain.");
		persephoneDialogue.AddDialogue(0, "Persephone - However, as you were taken in error, my husband has graciously seen fit to make the boulder easier to move, so that   you may earn your escape.");
		persephoneDialogue.AddDialogue(0, "Persephone - You must push the boulder to a '_' icon. This will be the button that allows you to open the door, represented with the 'U' icon. ");


		// Room 2 dialogue
		persephoneDialogue.AddDialogue(1, "Persephone - Many monsters roam the underworld. The Harpies (H) are one of them.");
		persephoneDialogue.AddDialogue(1, "Persephone - They have a whip-like attack that hits you whenever you are in front of them.Try to run whenever possible or use the boulder to put distance in between them.");
		persephoneDialogue.AddDialogue(1, "Persephone - Furthermore, this is my pet dog Cerberus (W). He will not chase you and is relatively tame. He must, however, fulfill his duties as the Guard Dog of the Underworld.");
		persephoneDialogue.AddDialogue(1, "Persephone - He uses an AOE attack that affects certain rows, causing you to take damage from him. ");
		persephoneDialogue.AddDialogue(1, "Persephone - You may use the boulder as a shield to absorb hits. Be careful how you use it as some puzzles require you to make sacrifices.");
		//Room 8 Ending Dialogue
		playerDialogue.AddDialogue(8, "You - *The breeze touches your skin as you exit the last dungeon. Your hair rustles in the wind.*");
		playerDialogue.AddDialogue(8, "You - *You can feel the gentle easing of pressure against your chest as the heat against your flesh cools.*");
		playerDialogue.AddDialogue(8, "You - *The air is filled with the pleasant, subtle scent of flowers. When you look up at the sky, there isn't any blazing lava or completely dark sky.*");
		playerDialogue.AddDialogue(8, "You - *You are met with the most beautiful blue you have ever seen as sunshine trickles through the dappled grove.*");
		playerDialogue.AddDialogue(8, "You - *Now, with a crunch beneath your feet, you move forward in search of the next day. You approach the next city, Athens.*");
}
//Extra ending for room 8 specifically
void Menu::showEnding()
{
	int endingRoom = 8;

	while (!playerDialogue.IsFinished(endingRoom))
	{
		system("cls");

		playerDialogue.DisplayDialogue(endingRoom);
		playerDialogue.NextDialogue(endingRoom);
	}
}

void Menu::printTitle() {
	std::cout << "==============================================================================" << std::endl;
	std::cout << std::endl;
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
	std::cout << std::endl;
	std::cout << "==============================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Press 'Enter' to start the game." << std::endl;
	std::cout << "Press 0 to view game controls." << std::endl;
	std::cout << "It is recommended to play in full screen." << std::endl;
}

void Menu::showTitleScreen() {
	while (true) {
		system("cls");
		printTitle();

		char input = _getch(); // Wait for key press

		switch (input) {

		case '\r': // Enter key
			system("cls");
			return; // Exit title screen when control is handed over

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
}

void Menu::showControls() {
	while (true) {
		system("cls");

		std::cout << "==============================================================================" << std::endl;
		std::cout << "				Game Controls" << std::endl;
		std::cout << "==============================================================================" << std::endl;
		std::cout << std::endl;
		std::cout << "[g] > Allows / Disallows player to push boulder" << std::endl;
		std::cout << "[k] > Moves on to next dialogue line" << std::endl;
		std::cout << "[i] > Opens / Closes player's inventory" << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		std::cout << "				Movement Controls" << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		std::cout << "[W] > Move player Up" << std::endl;
		std::cout << "[A] > Move player Left" << std::endl;
		std::cout << "[S] > Move player Down" << std::endl;
		std::cout << "[D] > Move player Right" << std::endl;
		std::cout << "																		" << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "*Press '0' to return to the game screen.*" << std::endl;

		char input = _getch();

		switch (input) {

		case '0':
			return;  // Return to showGameScreen()

		default:
			break;
		}
	}
}



void Menu::showCredits() {
	while (true) {
		system("cls");
		std::cout << "==============================================================================" << std::endl;
		std::cout << "				Credits" << std::endl;
		std::cout << "==============================================================================" << std::endl;
		std::cout << std::endl;

		std::cout << " Thanks for playing Curse of Sisyphus!" << std::endl;
		std::cout << std::endl;
		std::cout << " Jayden - Rooms, Room art, Boulders" << std::endl;
		std::cout << " Joshua - Story writer, Enemy coding, Karma system" << std::endl;
		std::cout << " Elkan - Player Inventory, Encounter " << std::endl;
		std::cout << " Zi Ming - PLayer Movement coding, Game UI, Reset Feature" << std::endl;
		std::cout << " Alexander - Environmental aspects (Walls, Button x Door), Final Boss" << std::endl;

		std::cout << std::endl;
		std::cout << "==============================================================================" << std::endl;

		char input = _getch();

		switch (input) {

		case 'z':
			return;

		default:
			break;
		}
	}
}

bool Menu::handleGameInput(char inputt)
{
	switch (inputt)
	{
	case 'i':
	case 'I':
		Inventory::GetInstance().RunInventory();
		return true;

	case '0':
		showControls();
		return true;

	case 'k':
	case 'K':
	{
		int currentRoom = mapHandler->getcurrentmap();

		while (!persephoneDialogue.IsFinished(currentRoom))
		{
			system("cls");

			persephoneDialogue.DisplayDialogue(currentRoom);
			persephoneDialogue.NextDialogue(currentRoom);
		}

		return true;
	}

	case 'z':
	case 'Z':
		showCredits();
		return true;

	default:
		return false;
	}
}
