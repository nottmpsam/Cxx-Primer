#include <iostream>
#include <fstream>

int main(int argc, char**argv)
{
    /*
    std::cout << "This system can gereate up to " << TMP_MAX 
        << " temporary nsames of up to " << L_tmpnam
        << " characters.\n";
    char a[L_tmpnam] = {'\0'};
    std::cout << "Here are names:\n";
    for (int i = 0; i < 10; ++i) {
        tmpnam(a);
        std::cout << a << std::endl;
    }*/
    if (argc < 2) {
        std::cerr << "Error. U didn't enter 2 files.\n"
            << "1st - from && 2nd - to\n";
        std::exit(EXIT_FAILURE);
    }
    std::ifstream fi(argv[1]);
    std::ofstream fo(argv[2]);
    char ch;
    while (fi >> ch) {
        fo << ch;
    }
    fi.close();
    fo.close();
    return 0;
}
