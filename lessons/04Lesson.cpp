#include <iostream>
#include <string>

using namespace std;

//typename = any data type
template<typename T1, typename T2> T1 add(T1 x, T2 y){
	return x+y;
}

int main(){
	//A string using one function
	string a = "a";
	string b = "b";

	cout << add(a, b) <<endl;

	//Add ints in same function
	cout << to_string(add(1, 2)) <<endl;

	return 0;
}
