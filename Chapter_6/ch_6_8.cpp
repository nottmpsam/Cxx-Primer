#include <iostream>
#include <fstream>
#include <cctype>

const int Size = 50;
int count_symbols(const char * );

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;

    char filename[Size];
    cout << "Enter your file name: ";
    cin >> filename;
    
    cout << count_symbols(filename)
    << "\nGood luck!\n";
    return 0;
}

int count_symbols(const char * name)
{
    std::ifstream InFile;
    InFile.open(name);
    std::cout << "Name of your entered file is: "
    << name << std::endl;

    if (!(InFile.is_open())) {  
        std::cout << "Can't open file! \n";
        return false;
    }

    char ch;
    int count{};
    while ((InFile.get(ch)) && ch != EOF)
    {
        if (!(isspace(ch))) {
                   ++count;
                }
    }
    std::cout << "Symbols in your file(without spaces): ";
    InFile.close();
    return count;
}
    