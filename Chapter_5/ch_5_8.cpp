#include <iostream>
#include <cstring> 

const int Size = 100;
int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	const char toStop[5] = "done";
	
	char words[Size];
	cout << "Enter \"done\" to stop programm." << endl;
	cin.getline(words, Size);
	
	int words_count{};
	while(strcmp(words, toStop))
	{
		++words_count;
		cin.getline(words, Size);
	}
    
    cout << "Done! " << words_count << " words."  <<endl;

	return 0;
}
