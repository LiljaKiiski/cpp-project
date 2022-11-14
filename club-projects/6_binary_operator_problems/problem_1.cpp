#include <iostream>

using namespace std;

void swap (int &num1, int &num2){
	num1 = num1^num2;
	num2 = num1^num2;
	num1 = num1^num2;
}

int main(){
	int num1 = 6;
	int num2 = 3;
	
	cout << num1 << " : " << num2 << endl;
	
	swap(num1, num2);

	cout << num1 << " : " << num2 << endl;

	return 0;
}
