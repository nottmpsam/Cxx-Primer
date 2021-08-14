#include <iostream>
#include <cstring>

struct stringy 
{
    char* str;
    int ct;
};

void set(stringy &cStringy, const char* str) 
{
    int strSize = strlen(str);
    cStringy.str = new char[strSize + 1];
    strcpy(cStringy.str, str);
}
void show(const stringy &cStringy, int count = 1)
{
    if (!count) ++count;
    count = (count < 0 ? -count : count);
    for (int i = 0; i < count; ++i) {
        std::cout << cStringy.str << std::endl;
    }
}
void show(const char* str, int count = 1)
{
    if (!count) ++count;
    count = (count < 0 ? -count : count);
    for (int i = 0; i < count; ++i) {
        std::cout << str << std::endl;
    }
}
int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);

    show(beany);
    std::cout << "***" << std::endl;
    show(beany, 2);

    std::cout << "***" << std::endl;
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    std::cout << "***" << std::endl;
    show(testing, 3);
    show("Done!");
    delete [] beany.str;
}
