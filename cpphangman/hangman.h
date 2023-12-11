#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>

class HangmanGame {
public:
    HangmanGame();
    void play();

private:
    std::string chooseRandomWord();
    void displayHangman(int incorrectGuesses);
    void displayWord(const std::string& word, const std::string& guessedLetters);
    char getGuess();
    bool isGuessCorrect(char guess, const std::string& word);

    const int MAX_TRIES = 6;
    std::string word;
    int tries;
    std::string guessedLetters;
    bool gameWon;
};

#endif // HANGMAN_H
