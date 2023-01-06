#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
std::vector<int> findCharIndexesInString(std::string& str, const char c) {
  std::vector<int> results = {};
  int i = 0;
  for (auto& ch : str) {
    if (ch == c) {
      results.push_back(i);
    }
    i++;
  }
  return results;
}
std::vector<std::string> readFileLines(const char* fileName) {
  std::ifstream ifs(fileName);
  if (!ifs.is_open()) {
    return {};
  }
  std::vector<std::string> lines;
  for (std::string s; getline(ifs, s);) {
    lines.push_back(s);
  }
  ifs.close();
  return lines;
}

int main()
{
    std::vector<std::string> words = readFileLines("static/words.txt");
    if (words.size() == 0) {
      std::cout << "Cannot play without file static/words.txt!";
      return 1;
    }
    srand(time(NULL));
    int mistakes = 0;
    int index = rand() % words.size();
    std::string wordToGuess = words[index];
    bool guessed = false;
    bool run = true;
    while(mistakes < 10 && run)
    {
        int decision;
        std::string wordGuess;
        char letterGuess;
        std::cout << "Enter 0 to guess the word, 1 to guess a letter:\n";
        std::cin >> decision;
        switch(decision) 
        {
            default:
                std::cout << "That's not a valid choice.\n";
                break;
            case 0:
                std::cout << "You have decided to guess the word.\n";
                std::cout << "Enter a word: \n";
                std::cin >> wordGuess;
                if(wordGuess == wordToGuess){
                    std::cout << "You have guessed the word!\n";
                    guessed = true;
                    run = false;
                } else {
                    std::cout << "Try Again.\n";
                    mistakes++;
                }
                break; 
            case 1:
                std::cout << "You have decided to guess a letter.\n";
                std::cout << "Enter a letter: \n";
                std::cin >> letterGuess;
                auto indexes = findCharIndexesInString(wordToGuess, letterGuess);
                if (indexes.size() > 0) {
                    for (auto index : indexes) {
                      std::cout << "Position #" << index + 1 << std::endl;     
                    }
                } else {
                    std::cout << "That letter doesn't exist.\n";
                    mistakes++;
                }
                break;
        }
    }
    if (guessed == false) {
        std::cout << "You lost!" << std::endl;
        std::cout << "Actual word: " << wordToGuess << std::endl;
    } else {
        std::cout << "Congratulations! You guessed the word!" << std::endl;
        std::cout << "Mistakes: " << mistakes << std::endl;
    }
    return 0;
}
