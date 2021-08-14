#include <iostream>
#include <cstring>
#include <cctype>
class String
{
private:
    char * str;             // pointer to string
    int len;                // length of string
    static int num_strings; // number of objects
    static const int CINLIM = 80;  // cin input limit
public:
// constructors and other methods
    String(const char * s); // constructor
    String();               // default constructor
    String(const String &); // copy constructor
    ~String();              // destructor
    int length () const { return len; }
// overloaded operator methods    
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
// overloaded operator friends
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend std::ostream & operator<<(std::ostream & os, const String & st);
    friend std::istream & operator>>(std::istream & is, String & st);
// static function
    static int HowMany();
// ~~~~
    //String operator+(const String &t0) const;
   // friend String operator+(const char *t0, const String &t1);
    //~~~
    friend String operator+(const String &t0, const String &t1);
    //automatic conversion in args, but slower that 1way
    void stringlow();
    void stringup();
    int charInString(char) const;
};
int String::charInString(char c) const
{
    char*temp = str;
    int count = 0;
    while (*temp) 
    {
        if (c == *temp) {
            ++count;
        }
        ++temp;
    }
    return count;
}
void String::stringup()
{
    char* temp = str;
    while (*temp) {
        *temp = toupper(*temp);
        ++temp;
    }
}
void String::stringlow()
{
    char* temp = str;
    while (*temp) {
        *temp = tolower(*temp);
        ++temp;
    }
}
String operator+(const String &t0, const String &t1)
{
    char* tempStr = new char[t0.len + t1.len + 1];
    strcpy(tempStr, t0.str);
    strcpy(strlen(tempStr) + tempStr, t1.str);
    String string(tempStr);
    delete [] tempStr;
    return string;
}
/*
String operator+(const char* t0, const String &t1)
{
    return t1 + t0;
    //t1.operator(t0);
    //t0->String
}
String String::operator+(const String &t0) const
{
    char* temp = new char[t0.len + len + 1];
    strcpy(temp, str);
    strcpy(strlen(temp) + temp, t0.str);
    String toReturn(temp);
    delete [] temp;
    return toReturn;
}*/
int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char * s)     // construct String from C string
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];       // allot storage
    std::strcpy(str, s);           // initialize pointer
    num_strings++;                 // set object count
}

String::String()                   // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0';                 // default string
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char [len + 1];  // allot space
    std::strcpy(str, st.str);  // copy string to new location
}

String::~String()                     // necessary destructor
{
    --num_strings;                    // required
    delete [] str;                    // required
}

// overloaded operator methods

    // assign a String to a String
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

    // assign a C string to a String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

    // read-write char access for non-const String
char & String::operator[](int i)
{
    return str[i];
}

    // read-only char access for const String
const char & String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

    // simple String output
std::ostream & operator<<(std::ostream & os, const String & st)
{
    os << st.str;
    return os;
}

    // quick and dirty String input
std::istream & operator>>(std::istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
// sayings2.cpp -- using pointers to objects
// compile with string1.cpp
int main()
{
    /*
    String first("Hello");
    String second(" World!\nWelcome to the club, buddy.");
    String third = first + second;
    //std::cout << third << std::endl;
    third = third + "\nThank you!";
    //std::cout << third << std::endl;
    third = "\nOh, Sh*t! Here we go again: \n" + third + "\txD";
    std::cout << third << std::endl;
    String micro("BIGbOY");
    micro.stringlow();
    std::cout << micro << std::endl;
    String nano("littleBoy");
    nano.stringup();
    std::cout << nano << " " << nano.charInString('T') << std::endl;
    */
    using std::cout;
    using std::cin;
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    cout << "The string\n" << s2 << "\ncontains " << s2.charInString('A')
        << " 'A' characters in it.\n";
    s1 = "red";
    String rgb[3] = { String(s1), String("green"), String("blue") };
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans) 
    {
        ans.stringlow();
        for (int i = 0 ; i < 3; ++i)
        {
            if (ans == rgb[i])
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success) break;
        else cout << "Try again!\n";
    }
    cout << "Bye\n";
    return 0;
}


