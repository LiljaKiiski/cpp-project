#include <fstream>
#include <iostream>
#include <map>

using namespace std;

//Notes

//mv5?

//Indexing is hashing
//Taking data and chunking it over to a spot

//Point from one array to another

//Hashing functions can mess up

//Chaining

//Buckets
//Hashmap collision blow up

//Treemap in java, map in c
//Hashmap in java, unordered map in c

//Given file of data and how frequently workds appear

//Challenge: Remove commas and periods from sentences in words.txt
int main(){ 
	ifstream fint("new_words.txt"); //Read file
	map<string, int> words;
	string current;

	//While fint can keep reading
	while (fint >> current){
		words[current]++;
	}

	string input;
	cout << "Enter word: \n";
	cin >> input;

	cout << "There are " << to_string(words[input]) << " instances of that word \n";
}
