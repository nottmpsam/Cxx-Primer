#include <iostream>
const int Size = 50;

struct CandyBar
{
	char name[Size];
	float weight;
	int callory;
};

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	CandyBar sweats[3]
	{
	 {"Mocha Munch", 2.3, 350},
	 {"Gucha Gang", 3.3, 500},
	 {"GL MyBoy", 9.7, 100}
	};
	cout << sweats[0].name << " " << sweats[0].weight << " " << sweats[0].callory << endl;
	cout << sweats[1].name << " " << sweats[1].weight << " " << sweats[1].callory << endl;
	cout << sweats[2].name << " " << sweats[2].weight << " " << sweats[2].callory << endl;
	return 0;
}
