// static.cpp -- using a static local variable
#include <iostream>
void strcount(std::string &str);
int main()
{
    std::string str{""};
    std::cout << "Enter a line:\n";
    std::getline(std::cin, str);
    while (str != "") {
        strcount(str);
        std::getline(std::cin, str);
    }
    std::cout << "Bye!\n";
    return 0;
}
void strcount(std::string &str)
{
    static int total{};
    int count = str.length();
    total += count;
    std::cout << "Total characters: " << total
        << std::endl << "Current count of characters: " << count 
        << std::endl;
}
/*
#include <iostream>
// constants
const int ArSize = 10;

// function prototype
void strcount(const char * str);

int main()
{
    using namespace std;
    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);
    while (cin)
    {
        cin.get(next);
        while (next != '\n')    // string didn't fit!
            cin.get(next);      // dispose of remainder
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "Bye\n";
// code to keep window open for MSVC++
cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
    return 0;
}

void strcount(const char * str)
{
    using namespace std;
    static int total = 0;        // static local variable
    int count = 0;               // automatic local variable

    cout << "\"" << str <<"\" contains ";
    while (*str++)               // go to end of string
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
*/
