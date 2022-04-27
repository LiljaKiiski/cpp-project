#include <iostream>

using namespace std;

bool number_is_odd(int num){
        if (num&1){ //Last digit is 1, so odd
                return true;
        }

        return false;
}

int main(){
	return 0;
}
