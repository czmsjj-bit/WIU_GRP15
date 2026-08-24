#include "Dialogue.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

// Constructor
Dialogue::Dialogue() : currentIndex(0) {

}

// Destructor
Dialogue::~Dialogue() {

}

// Add a dialogue line
void Dialogue::AddDialogue(const std::string& text) {
    dialogueTexts.push_back(text);
}

// Display the current dialogue line
void Dialogue::DisplayDialogue() const {
    if (dialogueTexts.empty()) {
        std::cout << "(No dialogue set)" << std::endl;
        return;
    }

    if (currentIndex < dialogueTexts.size()) {

        // Clear the console
        system("cls");

        // Display current dialogue
        std::cout << dialogueTexts[currentIndex] << std::endl;

        // Wait until the player presses 'k'
        std::cout << "\nPress 'k' to continue...";

        char key;

        do {
            key = _getch();
        } while (key != 'k');
    }
}

// Move to the next dialogue line
void Dialogue::NextDialogue() {
    if (currentIndex < dialogueTexts.size()) {
        currentIndex++;
    }
}

// Check if all dialogue has been displayed
bool Dialogue::IsFinished() const {
    return currentIndex >= dialogueTexts.size();
}

// Clear all dialogue
void Dialogue::ClearDialogue() {
    dialogueTexts.clear();
    currentIndex = 0;
}