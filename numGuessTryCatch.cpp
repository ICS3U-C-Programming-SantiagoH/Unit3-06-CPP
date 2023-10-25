// Copyright (c) 2023 Santiago Hewett All rights reserved.
//
// Created by: Santiago Hewett
// Date: Oct, 25, 2023
// This program will ask the user
// for a number and will check if it is not a integer
// and then tell the user if they guessed correctly using random number

#include <iostream>

// Include this for std::setprecision

#include <iomanip>
#include <random>

int main() {
    // create a random seed value

    std::random_device rd;

    // create the sequence for number generator

    std::mt19937 gen(rd());

    // declare userGuess and correctGuess variable

    std::string userGuessAsString;
    int userGuessAsInteger;
    int correctGuess;

    // declare constants

    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 9;

    // get the userGuess and display message

    std::cout << "This program asks the user for the a number from ";
    std::cout << "\n1 to 9  and then displays if you guess correctly or not";
    std::cout << "\nwith the answer changing each time.";
    std::cout << "\nEnter your guess between 1 and 9: ";
    std::cin >>
        userGuessAsString;

    // Create a distribution between 1 and 9

    std::uniform_int_distribution<int> distribution(MIN_NUMBER, MAX_NUMBER);

    // generate correctGuess

    correctGuess = distribution(gen);

    // Try catch statement
    try {
        userGuessAsInteger = std::stoi(userGuessAsString);

        // Check if the user guess is equal to correct guess
        if (userGuessAsInteger == correctGuess) {
            // display that the user answer is correct

            std::cout << "\n";
            std::cout << "Congratulations, you guessed correctly!";
        } else {
            // display that the user answer is incorrect
            std::cout << "\n";
            std::cout << "Please guess again, the correct answer was "
                    << correctGuess << "";
    }
    } catch (std::invalid_argument) {
        // The user did not enter an integer.
        std::cout << "\n";
        std::cout << userGuessAsString << " is not an integer.\n";
    }
    // What is shows every time
    std::cout << "\n";
    std::cout << "Thanks for playing!\n";
}
