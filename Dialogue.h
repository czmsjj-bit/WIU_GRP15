#pragma once
#include <string>
#include <vector>

class Dialogue {
private:
    std::vector<std::string> dialogueTexts;
    int currentIndex;

public:
    Dialogue();
    ~Dialogue();

    void AddDialogue(const std::string& text);
    void DisplayDialogue() const;
    void NextDialogue();
	void ClearDialogue();

    bool IsFinished() const;
};