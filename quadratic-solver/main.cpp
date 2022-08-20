#include <iostream>
#include <cmath>

double triGetX1();
double triGetX2();
double biGetX();

double a;
double b;
double c;

using namespace std;

int main(){
	cout << "a: ";
	cin >> a;

	cout << "b: ";
	cin >> b;

	cout << "c: ";
	cin >> c;

	cout << "The equation is: ";
	cout << a << "x² + " << b << "x + " << c << " = 0" << endl; 

	//X = 0
	if ( (a == 0 && b == 0 && c == 0) || (a == 0 && b != 0 && c == 0)){
		cout << "X is 0" << endl;
	
	//Binomial
	} else if (a == 0 && b != 0 && c != 0){
		cout << "X is " << biGetX() << endl;
	
	//Trinomial
	} else if (!isnan(triGetX1()) || !isnan(triGetX2())){
		cout << "X is either " << triGetX1() << " or "<< triGetX2() << endl;

	//No solution	
	} else {
		cout << "No solution" << endl;
	}

	return 0;
}

//Binomial answer
double biGetX(){
	return -c / b;
}

//Trinomial answer 1
double triGetX1(){
	//Step one - simplify root
	double root = sqrt( b*b - 4 * a * c );

	//Step 2 a) - Solve with + 
	return (-b + root) / (2 * a);
}

//Trinomial answer 2
double triGetX2(){
        //Step one - simplify root
        double root = sqrt( b*b - 4 * a * c );

        //Step 2 a) - Solve with -
        return (-b - root) / (2 * a);
}
