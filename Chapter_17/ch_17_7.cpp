#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>

void showStr(const std::string &str)
{
    std::cout << str << "\n";
}

class Store
{
    std::ofstream* out;
public:
    Store() { out = nullptr; };
    explicit Store(std::ofstream& _out)
    {
        out = &_out;
    }
    void operator() (const std::string&);
};

void Store::operator() (const std::string& str)
{
    size_t size = str.size();
    out->write((char*)&size, sizeof(size));
    out->write((char*)&str[0], size);
}

void getStrs(std::ifstream& in, std::vector<std::string> &v)
{
    std::string str;
    size_t size = str.size();
    while (in.read((char*)&size, sizeof(size))) {
        str.resize(size);
        in.read((char*)&str[0], size);
        v.push_back(str);
    }
}

int main()
{
    using namespace std;
    vector<string> vostr;
    cout << "Enter strings (empty line to quit):\n";
    string temp;
    while (getline(cin, temp) && temp[0] != '\0') 
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), showStr);
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    Store x(fout);
    fout.close();
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open()) {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    getStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), showStr);
    return 0;
}
