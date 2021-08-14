#include <iostream>
#include <fstream>
#include <vector>
int main()
{
    std::cout << "Enter name of your file:" << std::endl;
    std::string str;
    getline(std::cin, str);
    std::ifstream inputFile(str);
    if (!inputFile.is_open()) {
        std::cerr << "the File: \"" << str << "\" didn't open" 
            << std::endl;
        exit(EXIT_FAILURE);
    }
    std::vector<std::string> wordlist;
    while (inputFile >> str) {
        wordlist.push_back(str);
    }
    //for (auto i: wordlist) std::cout << i << " ";
    //std::cout << std::endl;
    srand(time(0));
    char play;
    std::cout << "Will u play a word game? <y/n> ";
    std::cin >> play;
    play = tolower(play);
    while (play == 'y') {
        str = wordlist[rand() % wordlist.size()];
        std::string attempt(str.size(), '-');
        std::string badchars;
        int guesses = 7;
        std::cout << "Guess my secret word. It has " << str.size()
            << "letters, and you guess\n"
            << "one letter at a time. You get" << guesses 
            << "wrong guesses.\n";
        std::cout << "Your word: " << attempt << std::endl;
        while (guesses > 0 && attempt != str) {
            char letter;
            L:
            std::cout << "Guess a letter: ";
            std::cin >> letter;
            if (badchars.find(letter) != std::string::npos
                    || attempt.find(letter) != std::string::npos) {
                std::cout << "You already guessed that. Try again. \n";
                goto L;
            }
            int loc = str.find(letter);
            if (loc == std::string::npos) {
                std::cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;
            } else {
                std::cout << "Good guees!\n";
                attempt[loc] = letter;
                loc = str.find(letter, loc + 1);
                while (loc != std::string::npos) {
                    attempt[loc] = letter;
                    loc = str.find(letter, loc + 1);
                }
            }
            std::cout << "Your word " << attempt << std::endl;
            if (attempt != str) {
                if (badchars.length() > 0) {
                    std::cout << "Bad choices: " << badchars << std::endl; 
                }
                std::cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0) {
            std::cout << "That's right!\n";
        } else {
            std::cout << "Sorry, the word is " << str << std::endl;
        }
        std::cout <<"Will u play another? <y/n> ";
        std::cin >> play;
        play = tolower(play);
    }
    inputFile.close();
    return 0;
}
