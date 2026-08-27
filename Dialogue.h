#pragma once
#include <string>
#include <vector>

class Dialogue {
private:
    // Each room has its own set of dialogue lines
    std::vector<std::vector<std::string>> dialogueTexts;

    // Keeps track of which line is currently being displayed
    std::vector<int> currentIndex;

public:
    Dialogue();
    ~Dialogue();

    // Add dialogue to a specific room
    void AddDialogue(int roomNumber, const std::string& text);

    // Display the current dialogue for a specific room
    void DisplayDialogue(int roomNumber) const;

    // Move to the next dialogue line
    void NextDialogue(int roomNumber);

    // Clear dialogue from a specific room
    void ClearDialogue(int roomNumber);

    // Check if the current room's dialogue is finished
    bool IsFinished(int roomNumber) const;
};