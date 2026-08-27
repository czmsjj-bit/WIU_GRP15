#include "Dialogue.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

// Constructor
Dialogue::Dialogue() {
    dialogueTexts.resize(9);
    currentIndex.resize(9, 0);
}

// Destructor
Dialogue::~Dialogue() {

}

// Add a dialogue line to a specific room
void Dialogue::AddDialogue(int roomNumber, const std::string& text) {

    // Check that the room number is valid
    if (roomNumber >= 0 && roomNumber < dialogueTexts.size()) {
        dialogueTexts[roomNumber].push_back(text);
    }
}

// Display the current dialogue line for a specific room
void Dialogue::DisplayDialogue(int roomNumber) const {

    // Check that the room number is valid
    if (roomNumber < 0 || roomNumber >= dialogueTexts.size()) {
        return;
    }

    // Check if the room has any dialogue
    if (dialogueTexts[roomNumber].empty()) {
        std::cout << "(No dialogue set)" << std::endl;
        return;
    }

    // Check if there are still dialogue lines to display
    if (currentIndex[roomNumber] < dialogueTexts[roomNumber].size()) {

        // Clear the console
        system("cls");

        // Display current dialogue
        std::cout << dialogueTexts[roomNumber][currentIndex[roomNumber]] << std::endl;

        // Wait until the player presses 'k'
        std::cout << "\nPress 'k' to continue...";

        char key;

        do {
            key = _getch();
        } while (key != 'k');
    }
}

// Move to the next dialogue line
void Dialogue::NextDialogue(int roomNumber) {

    if (roomNumber < 0 || roomNumber >= currentIndex.size()) {
        return;
    }

    currentIndex[roomNumber]++;
}

// Check if all dialogue for the specified room has been displayed
bool Dialogue::IsFinished(int roomNumber) const {

    // Check that the room number is valid
    if (roomNumber < 0 || roomNumber >= dialogueTexts.size()) {
        return true;
    }

    return currentIndex[roomNumber] >= dialogueTexts[roomNumber].size();
}

// Clear all dialogue from a specific room
void Dialogue::ClearDialogue(int roomNumber) {

    // Check that the room number is valid
    if (roomNumber < 0 || roomNumber >= dialogueTexts.size()) {
        return;
    }

    dialogueTexts[roomNumber].clear();

    // Reset the dialogue index
    currentIndex[roomNumber] = 0;
}