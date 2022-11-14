#include <iostream>

using namespace std;

template<typename T1, typename T2> int search(T1, T2);

int main(){
	string arr[3] {"1", "5", "6"};

	cout << to_string(search(arr, "5")) << endl;

	return 0;
}


template<typename T1, typename T2> int search(T1 array, T2 item){
	int arr_len = sizeof array / sizeof array[0];
	
	for (int x = 0; x < arr_len; x++){
		if (array[x] == item){
			return x;
		}
	}
	return -1;
}


