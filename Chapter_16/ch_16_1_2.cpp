#include <iostream>
#include <algorithm>
#include <cctype>
#include <iterator>

bool isPalindrome(const std::string &st)
{

    std::string temp;
    std::copy_if(st.begin(), st.end(), std::insert_iterator<std::string>(temp, temp.begin()), isalpha);
    for (int i = 0, j = temp.size() - 1; i <= j; ++i, --j) {
        temp[i] = tolower(temp[i]);
        temp[j] = tolower(temp[j]);
        if (temp[i] != temp[j]) {
            return false;
        }
    }
    return true;
}
int main()
{
    std::string str;
    getline(std::cin, str);
    if (isPalindrome(str)) {
        std::cout << "Your string is Palindrome\n";
    } else {
        std::cout << "Your string is not Palindrome\n";
    }
    return 0;
}
