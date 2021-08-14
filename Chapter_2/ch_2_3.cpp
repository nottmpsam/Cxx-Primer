#include <iostream>

void display_1(void);
void display_2(void);

int main(void)
{
	display_1();
	display_2();

	return 0;
}

void display_1(void)
{
	for(int i = 0; i < 2; ++i)
		std::cout << "Three blind mice"  << std::endl;
}
void display_2(void)
{
	for(int i = 0; i < 2; ++i)
		std::cout << "See how they run" << std::endl;
}