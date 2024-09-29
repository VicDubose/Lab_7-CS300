#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "randword.h" // having issues making a interface will ask during TA/ Lab
// will i loose points for STD namespace ? 


std::string ChooseRandomWord(const std::set<std::string>& wordSet) {
    std::vector<std::string> wordList(wordSet.begin(), wordSet.end());
    
 std::cout << "This is HangMan choose your letters wisely  " << '\n';
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Set the range for the random number generator to the wordset. (https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/)
    int minRange = 0;
    int maxRange = static_cast<int>(wordList.size()) - 1;

    int randomIndex = minRange;
    for (int i = 0; i < 1; ++i) {
        randomIndex = minRange + std::rand() % (maxRange - minRange + 1);
    }
    // Return the word at the random index look back in CS300-500_04 for help with random number generation. 
    return wordList[randomIndex];
}

int main() {
    std::set<std::string> wordSet = {
        "apple", "banana", "grape", "peach", "plum",
        "mango", "berry", "lemon", "lime", "kiwi","happy","hello","help"
    };
    std::string secretWord = ChooseRandomWord(wordSet);
    std::string displayWord(secretWord.size(), '_');
    std::set<char> guessedLetters;
    int incorrectGuesses = 0;
    const int maxIncorrectGuesses = 8;

    while (incorrectGuesses < maxIncorrectGuesses) {
        std::cout << "Current word: ";
        for (char c : displayWord) {
            std::cout << c << ' ';
        }
        std::cout << "\nGuess a letter: ";

        char guess;
        std::cin >> guess;
	
        if (guessedLetters.find(guess) != guessedLetters.end()) {
            std::cout << "You already guessed that letter.\n";
            continue;
        }
        guessedLetters.insert(guess);
        bool correctGuess = false;
        for (size_t i = 0; i < secretWord.size(); ++i) {
            if (secretWord[i] == guess) {
                displayWord[i] = guess;
                correctGuess = true;
            }
        }

        if (correctGuess) {
            std::cout << "Good guess!\n";
        } else {
            ++incorrectGuesses;
            std::cout << "Incorrect guess, your one step closer to the noose. You have " << (maxIncorrectGuesses - incorrectGuesses) << " guesses left.\n";
        }

        if (displayWord == secretWord) {
            std::cout << "Congratulations! HangMan You guessed the word: " << secretWord << '\n';
            return 0;
        }
    }
    std::cout << "Game over! The secret word was: " << secretWord <<" better luck next time ",'\n';
    return 0;
}
