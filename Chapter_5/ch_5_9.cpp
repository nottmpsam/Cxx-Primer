#include <iostream>
#include <cstring> 

//const int Size = 100;
int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	const string toStop = "done";
	string words;

	cout << "Enter \"done\" to stop programm." << endl;
	getline(cin, words);
	
	int words_count{};
	while (words != toStop)
	{
		++words_count;
		cin >> words;		
	}
    
    cout << "Done! " << words_count << " words."  <<endl;

	return 0;
}
