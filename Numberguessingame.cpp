
//Internship Task for Codsoft
//Number guessing game

#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(0)));
    
    // Generate a random number between 1 and 100
    int SecretNumber = rand() % 100 + 1;
    
    int Guess;
    int Attempts = 0;
    
    cout << "Welcome to the Guess the Number game!\n";
    cout << "I have selected a number between 1 and 100.\n";
    
    do {
        // Ask the user to guess the number
        cout << "Enter your guess: ";
        cin >> Guess;
        
        Attempts++;
        
        // Provide feedback based on the guess
        if (Guess < SecretNumber) {
            cout << "Too low! Try again.\n";
        } else if (Guess > SecretNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number " << SecretNumber << " correctly!\n";
            cout << "Number of attempts: " << Attempts << "\n";
        }
        
    } while (Guess != SecretNumber);
    
    return 0;
}