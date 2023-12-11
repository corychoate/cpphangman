#include "hangman.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

HangmanGame::HangmanGame() {
    std::srand(std::time(0));
    word = chooseRandomWord();
    tries = 0;
    guessedLetters = "";
    gameWon = false;
}

std::string HangmanGame::chooseRandomWord() {
    const std::string words[] = { "apple", "banana", "orange", "grape", "strawberry", "melon" };
    return words[rand() % (sizeof(words) / sizeof(words[0]))];
}

void HangmanGame::displayWord(const std::string& word, const std::string& guessedLetters) {
    bool allLettersGuessed = true;

    for (char letter : word) {
        if (guessedLetters.find(letter) != std::string::npos) {
            std::cout << letter << " ";
        }
        else {
            std::cout << "_ ";
            allLettersGuessed = false;
        }
    }

    std::cout << "\n";

    if (allLettersGuessed) {
        std::cout << "Congratulations! You guessed the word: " << word << "\n";
        gameWon = true;
    }

    std::cout << "\n";  // Add a space between turns
}

void HangmanGame::displayHangman(int incorrectGuesses) {
    std::cout << "Incorrect guesses: " << incorrectGuesses << "\n";

    // Display the hangman based on the number of incorrect guesses
    switch (incorrectGuesses) {
    case 1:
        std::cout << " --------\n";
        std::cout << " |/     |\n";
        std::cout << " |      O\n";
        std::cout << " |        \n";
        std::cout << " |         \n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << "_|___________\n";
        break;
    case 2:
        std::cout << " --------\n";
        std::cout << " |/     |\n";
        std::cout << " |      O\n";
        std::cout << " |      |  \n";
        std::cout << " |         \n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << "_|___________\n";
        break;
    case 3:
        std::cout << " --------\n";
        std::cout << " |/     |\n";
        std::cout << " |      O\n";
        std::cout << " |     /|  \n";
        std::cout << " |         \n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << "_|___________\n";
        break;
    case 4:
        std::cout << " --------\n";
        std::cout << " |/     |\n";
        std::cout << " |      O\n";
        std::cout << " |     /|\\\n";
        std::cout << " |        \n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << "_|___________\n";
        break;
    case 5:
        std::cout << " --------\n";
        std::cout << " |/     |\n";
        std::cout << " |      O\n";
        std::cout << " |     /|\\\n";
        std::cout << " |     /   \n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << "_|___________\n";
        break;
    case 6:
        std::cout << " --------\n";
        std::cout << " |/     |\n";
        std::cout << " |      O\n";
        std::cout << " |     /|\\\n";
        std::cout << " |     / \\\n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << "_|___________\n";
        break;
    }

    std::cout << "\n";  // Add a space between turns
}

char HangmanGame::getGuess() {
    std::cout << "Enter your guess: ";
    char guess;
    std::cin >> guess;
    return guess;
}

bool HangmanGame::isGuessCorrect(char guess, const std::string& word) {
    return word.find(guess) != std::string::npos;
}

void HangmanGame::play() {
    while (tries < MAX_TRIES && !gameWon) {
        displayWord(word, guessedLetters);
        displayHangman(tries);

        char guess = getGuess();

        if (isGuessCorrect(guess, word)) {
            std::cout << "Correct!\n";
            guessedLetters += guess;
        }
        else {
            std::cout << "Incorrect!\n";
            tries++;
        }

        std::cout << "\n";  // Add a space between "correct/incorrect" and the hangman visual
    }

    // Display the final hangman visual if the game is lost
    if (!gameWon) {
        displayWord(word, guessedLetters);
        displayHangman(6);  // Display the final hangman visual
        std::cout << "Sorry, you ran out of tries. The correct word was: " << word << "\n";
    }
    else {
        std::cout << "Congratulations! You guessed the word: " << word << "\n";
    }
}