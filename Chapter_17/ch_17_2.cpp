#include <iostream>
#include <fstream>
int main(int argc, char** argv)
{
    if (argc == 1) {
        std::cerr << "There is no file to output!" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::ofstream f(argv[1]);
    std::cout << argv[1] << std::endl;
    char ch;
    while (std::cin.get(ch) && ch != '\n') {
        f << ch;
    }
    f.close();
    return 0;
}
