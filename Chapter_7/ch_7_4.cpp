// lotto.cpp -- probability of winning
#include <iostream>
// Note: some implementations require double instead of long double
long double probability(unsigned numbers, unsigned picks);
long double probabilityWithMegaNumber(unsigned int numbers, long double firstPr);
int main()
{
    using namespace std;
    double total, choices, megaNumber;
    cout << "Enter the total number of choices on the game card,\n"
            "the number of picks allowed,\n"
			"and the mega number: \n";
    while ((cin >> total >> choices >> megaNumber) && (megaNumber < total && choices <= total))
    {
        cout << "You have one chance in ";
       // cout << probability(total, choices);      // compute the odds
		long double firstPr = probability(total, choices);
		std::cout << probabilityWithMegaNumber(megaNumber, firstPr);
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye\n";
    // cin.get();
    // cin.get();
    return 0;
}

// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probabilityWithMegaNumber(unsigned int numbers, long double firstPr) {
	long double secondPr = 1.0 / numbers;
	return secondPr*firstPr;
}
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;  // here come some local variables
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p ; 
    return result;
}

