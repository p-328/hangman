#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    string words[12] = {"random", "deafened", "exodus", "subdermatoglyphic", "ambiguous", "graphics", "mangoes", "salamander", "solar", "kaleidoscope", "spectrum", "polarity"};
    srand(time(NULL));
    int attempts = 0;
    int index = rand() % 12;
    string wordToGuess = words[index];
    bool run = true;
    bool guessed = false;
    //cout << wordToGuess << endl;
    while(run){
        //cout << wordToGuess << endl;
        int decision;
        string wordGuess;
        char letterGuess;
        cout << "Enter 0 to guess the word, 1 to guess the letter:" << endl;
        cin >> decision;
        switch(decision) {
            default:
                cout << "That's not a valid choice." << endl;
                attempts = 100;
                break;
            case 0:
                cout << "You have decided to guess the word." << endl;
                cout << "Enter a word: " << endl;
                cin >> wordGuess;
                if(wordGuess == wordToGuess){
                    cout << "You have guessed the word!" << endl;
                    guessed = true;
                    run = false;
                } else {
                    cout << "Try Again." << endl;
                    attempts++;
                }
                break; 
            case 1:
                cout << "You have decided to guess a letter." << endl;
                cout << "Enter a letter: " << endl;
                cin >> letterGuess;
                if (wordToGuess.find(wordGuess) != string::npos) {
                    int position = wordToGuess.find(letterGuess) + 1;
                    cout << position << endl;
                } else {
                    cout << "That letter doesn't exist." << endl;
                    attempts++;
                }
                break;
        }
        //attempts++;
        if (attempts > 10){
            run = false;
        }
    }
    if (guessed == false) {
        cout << "You lost!" << endl;
    } else {
        cout << "Congratulations!" << endl;
        cout << "Attempts: " << attempts << endl;
    }
    return 0;
}