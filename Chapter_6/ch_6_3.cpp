#include <iostream>
#include <cstdlib>
void display_menu(void);
void try_again(void);
int main(void)
{	
	using std::cin;
	using std::cout;
	using std::endl;
	display_menu();
	char ch;
	bool fl = false;
	short t = 0;
	while(cin.get(ch) )
	{
		if(ch == '\n')
			continue;
		switch(ch)
		{
			case 'a':
			case 'A': cout <<"Sorry, but you have just a bad news: Soon is september. \n"; fl = true; break;
			case 'b':
			case 'B': cout << "LOL, there are no games for you! \n"; fl = true; break;
			case 'c':
			case 'C': cout << "Soc.media apps are not useful for you. \n"; fl = true; break;
			case 'd':
			case 'D': cout << "Books are better than films. Can't recommendate. \n"; fl = true; break;
			case 'q':
			case 'Q': fl = true; break;
			default : fl = false;
		}
		if (fl) break;
		else try_again();
		
	}
	cout << "Done!\n";

	return 0;
}
void display_menu(void)
{
	using std::cout;
	cout << "**Please enter one of the following choices: **\n";
	cout << "a) news " << "\tc) soc. media apps\n";
	cout << "b) game " << "\td) film \n";
	cout << "q - to exit menu\n"; 
}
void try_again(void)
{
	using std::cout;
	cout << "Please enter a d, c, b, a or q: \n";
}
