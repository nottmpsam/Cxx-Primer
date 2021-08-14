#include <iostream>
#include <cctype>
#include <cstdlib>

int main(void)
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "Enter '@' to quit!" << endl;
    char ch;
    //while ((ch = cin.get()) != '@')
   	while(cin.get(ch) && ch != '@')
    {
        if (isdigit(ch)) {
            continue;
        } else if (isupper(ch)) {
            cout << char(tolower(ch));
        } else if (islower(ch)) {
        	cout << char(toupper(ch));
        } else {
            cout << ch;
        }
        /*
        switch(ch)
        {
        case bool(isdigit(ch)): continue;
        case bool(isupper(ch)): cout << char(tolower(ch)); break;
        case bool(islower(ch)): cout << char(toupper(ch)); break;
        default: cout << ch;
   		}
   		*/The 2 awesome oxen ambled quietly across  5 meters of lawn. q
    }
    
    return 0;
}