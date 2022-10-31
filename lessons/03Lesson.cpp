#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

int main(){
	//Binary Search: finds values by going through midpoints of sorted array, going smaller of larger

	//Node:  stores a value or number, each node has two children
		
	//Big O Notation: Largest number of operations we need to take to get a particular algorithm tao take
		
	//Binary Tree Search:
	//	- Logrithmic = time complexity = log(n)
	//	- log(n) is normally smaller than n itself
	
	//Create a new Node
	Node n;

	//Get left node from n
	cout << to_string(n->data) << endl;
	return 0;
}
