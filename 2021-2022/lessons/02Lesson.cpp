#include <iostream>

//PROTOTYPES
int factorial(int);

using namespace std;

int main(){
	cout << to_string(factorial(2));

        return 0;
}

//RECURSION EXAMPLE
int factorial(int n){
        if (n == 1){
                return 1;
        }

        return n * factorial(n-1);
}
