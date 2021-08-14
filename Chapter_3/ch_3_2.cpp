#include <iostream>

int main(void)
{
	float foot, inch, lb;
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout << "Enter your height and weight. "
	<<"\nin foot: ";
	std::cin >> foot;
	std::cout << "in inch: ";
	std::cin >> inch;
	std::cout << "And weight in lb: ";
	std::cin >> lb;

	inch = foot * 12 + inch;
	inch *= 0.0254;
	lb /= 2.2;
	std::cout << "Metres: " << inch
	<< " | Kg: " << lb << std::endl;

	double BMI = lb / (inch * inch);
	std::cout << "Your body mass index (BMI)	: "
	<< BMI;

}