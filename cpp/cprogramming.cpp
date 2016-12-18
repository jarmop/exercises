/**
 * cprogramming.com practice problem solutions
 * http://www.cprogramming.com/challenge.html
 */

#include <iostream>

using namespace std;

/************* 1. ARRAY CHALLENGE *************
 * When completed, the following program should first fill in (by asking the user for input) and then list all the elements in an array.
 * http://www.cprogramming.com/complete/array.html
 */
void ArrayChallenge() {
    int array[8];
    for (int x = 0; x < 8; x++) {
        cin >> array[x];
    }
    for (int x = 0; x < 8; x++) {
        cout << array[x] << endl;
    }
}

/*********** 2. GUESSING GAME *********
 * The following program will act as a guessing game in which the user has eight tries to guess a randomly generated number.
 * The program will tell the user each time whether he guessed high or low.
 * http://www.cprogramming.com/complete/guessing.html
 */
void GuessingGame() {
    int n = 8;
    int correct = 5;
    int guess;
    for (int guess_number = 0; guess_number < 8; guess_number++) {
        cout << "Guess a number: " << endl;
        cin >> guess;
        if (guess == correct) {
            cout << "That's correct!" << endl;
            break;
        } else {
            cout << "Wrong!" << endl;
        }
    }
}

int main() {
//    ArrayChallenge();
    GuessingGame();
}