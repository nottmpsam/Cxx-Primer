#include <iostream>
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void show(const box* ptr);
void refreshVolume(box* ptr);
void enter(box* ptr);
int main()
{
	box temp;
	enter(&temp);
	show(&temp);
	refreshVolume(&temp);
	show(&temp);
	return 0;
}
void enter(box* ptr)
{
	std::cout << "Enter height: ";
	std::cin >> ptr->height;
	std::cout << "Enter width: ";
	std::cin >> ptr->width;
	std::cout << "Enter length: ";
	std::cin >> ptr->length;
	std::cout << "Enter volume: ";
	std::cin >> ptr->volume;
	
}
void refreshVolume(box*ptr)
{
	ptr->volume = ptr->height * ptr->width * ptr->length;
}
void show (const box* ptr) {
	std::cout << ptr->maker << 
		"\nHeight: " << ptr->height <<
		"\nWidth: " << ptr->width <<
		"\nLength: " << ptr->length << 
		"\nVolume: " << ptr->volume << 
		std::endl;
}
