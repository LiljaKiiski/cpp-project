#include <iostream>
#include <cmath>

double getX1();
double getX2();

double a = 6;
double b = 4;
double c = -2;

using namespace std;

int main(){

	cout << "The equation is: ";
	cout << a << "x² + " << b << "x + " << c << endl; 

	cout << "X is either " << getX1() << " or "<< getX2() << endl;

	return 0;
}

double getX1(){
	//Step one - simplify root
	double root = sqrt( pow(b, 2) - 4 * a * c );

	//Step 2 a) - Solve with + 
	return (-b + root) / (2 * a);
}

double getX2(){
        //Step one - simplify root
        double root = sqrt( pow(b, 2) - 4 * a * c );

        //Step 2 a) - Solve with -
        return (-b - root) / (2 * a);
}
