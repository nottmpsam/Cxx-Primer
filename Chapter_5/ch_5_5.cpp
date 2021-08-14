#include <iostream>
#include <array>
const int M = 12;
int main(void)
{
	const char* month[M] 
	{
		"January",
		"February",
		"March",
		"April",
	    "May",
	    "June",
	    "Jule",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    std::array<short, M> sells;
   	for(int i = 0; i < M; ++i)
   	{
   		std::cout << "How many books did you sell in " << *(month + i) << "? Enter here: ";
   		std::cin >> sells[i]; 
   	}
   	int total{};
   	for(int i = 0; i < M; ++i)
   	{
   		std::cout << month[i] << " | " << sells[i] << "books" << std::endl;
   		total += sells[i];
   	}

   	std::cout << "Total sells in this year: " << total <<" books " << std::endl;

	return 0;
}
