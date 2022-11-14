#include <iostream>
#include <string>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

//Search function for binary tree
bool search(Node* node, int value){
	if (node == nullptr) { //nullptr is null pointer, NULL is just null 
		return false;
	
	} else if (node->data == value){
		return true;
	}

	if (node->data >= value){ //Greater or equal
		return search(node->right, value);

	} else { //Less
		return search(node->left, value);
	} 
}

int main(){
	//Left node
	Node *nodeL = new Node;
	nodeL->data = 5;

	//Right node
	Node *nodeR;
	nodeR->data = 15;

	//Main node
	Node *node;
	node->data = 10;
	node->left = nodeL;
	node->right = nodeL;

	cout << search(node, 6) << endl;

	return 0;
}
