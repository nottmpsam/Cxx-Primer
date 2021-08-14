#include <iostream> 
#include <cctype>

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	cout << "Enter words (q to quit)" << endl;
	
	char ch;
	int glas {};
	int soglas {};
	int others {};

	while (cin.get(ch))
	{
		if (ch == 'q' || ch == 'Q')
		{
			int count{};
			while (!isspace(ch))
			{
				++count;
				cin.get(ch);
			}
			if (count == 1)
				break;
			++soglas;
		}
		else 
		{
			if (isspace(ch) || ispunct(ch))
			{
				while (isspace(ch) || ispunct(ch))
				{
					cin.get(ch);
				}
			}
		
			if (isdigit(ch))
			{
				 ++others;
				 while (!isspace(ch)) cin.get(ch);
				 continue;
			}

			switch (ch)
			{
				case 'a':
				case 'A': glas++; break;
				case 'e':
				case 'E':glas++; break;
				case 'i':
				case 'I':glas++; break;
				case 'o':
				case 'O':glas++; break;
				case 'u':
				case 'U':glas++; break;
				case 'y': 
				case 'Y': glas++; break;
				default: soglas++;
			}

		    while (!isspace(ch)) cin.get(ch);
		    
		}	

	}
	cout << glas << " words beginning with vowels\n"
	<< soglas << " words beginning with consonants\n"
	<< others << " others" << endl;

 	return 0;
}
