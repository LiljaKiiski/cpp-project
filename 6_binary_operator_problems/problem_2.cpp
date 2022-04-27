#include <iostream>

using namespace std;

bool is_power_of_2(int num){
	if ((num&-num) == num && num != 0){
		return true;
	}
	return false;
}

int main(){
	for (int x = 0; x < 10; x++){
		string _is_power = is_power_of_2(x) ? "true" : "false";
		cout << x << " is a power of 2: " << _is_power << endl;
	}

	return 0;
}
