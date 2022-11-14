#include <iostream>

using namespace std;

bool is_odd(int num){
        if (num&1){ //Last digit is 1, so odd
                return true;
        }

        return false;
}

int main(){
	for (int x = 0; x < 10; x++){
		string _is_odd = is_odd(x) ? "true" : "false";
		cout << x << " is odd: " << _is_odd << endl;
	}

	return 0;
}
