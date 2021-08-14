#include <iostream>
#include <cmath>
double calculate (double x, double y, double (*ptr) (double, double));
double add (double x, double y);
double multiply (double x, double y) ;
double dv (double x, double y);
double pw (double x, double y);
int main()
{
	std::cout << "Enter x and y: ";
	double x, y;
    const int N = 4;
    double (*ptr[N]) (double x, double y) = {add, multiply, dv, pw};
	while (std::cin >> x >> y) {
        for (int i = 0; i < N; ++i) {
            std::cout << calculate(x,y, ptr[i]) << std::endl;
        }
	}
	return 0;
}
double calculate (double x, double y, double (*ptr)(double x, double y))
{
    //retyrb (*ptr)(x,y) 
    //are equal
    return ptr(x,y);
}
double add (double x, double y) {
    std::cout << "Adding..." << std::endl;
	return x + y;
}
double multiply (double x, double y) {
    std::cout << "Multiply..." << std::endl;
	return x * y;
}
double dv (double x, double y) {
    std::cout << "Divide..." << std::endl;
	return x / y;
}
double pw (double x , double y) {
    std::cout << "Pow..." << std::endl;
    //return (!y)?1:((static_cast<int>(y)&1)?x:1)*pw(x*x,y/2);
    return pow(x,y);
}
