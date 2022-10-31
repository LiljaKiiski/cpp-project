#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//STRUCTURES
struct coordinate {
        int x;
        int y;
};

int main(){
	//VECTORS
	vector <int> v; //new vector
	v.push_back(8); //add to vector

	//ARRAYS
	int name[10]; //array

	//FILE IO
	ifstream fint("x.txt"); //read file
	ofstream fout("x.txt"); //write file

	int x;
	//file in
	fint >> x;

	//file out
	fout << x <<endl;

	coordinate k;

	k.x = 5;
	k.y = 10;
}
