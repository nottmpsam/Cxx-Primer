#include <iostream>


struct CandyBar
{
	std::string name;
	float weight;
	int callory;
};

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	CandyBar* sweats = new CandyBar[3];
	
	sweats->name = "Mocha Munch";
	sweats->weight = 2.3;
	sweats->callory = 350;
	
	(sweats + 1)->name = "Gucha Gang";
	(sweats + 1)->weight =3.3;
	(sweats + 1)->callory = 500;
	
	(sweats + 2)->name = "GL MyBoy";
	(sweats + 2)->weight = 9.7;
	(sweats + 2)->callory = 100;
	
	cout << sweats->name << " " << sweats->weight << " " << sweats->callory << endl;
	cout << sweats[1].name << " " << sweats[1].weight << " " << sweats[1].callory << endl;
	cout << (sweats+2)->name << " " << (sweats+2)->weight << " " << (sweats+2)->callory << endl;
	
	delete [] sweats;
	return 0;
}
