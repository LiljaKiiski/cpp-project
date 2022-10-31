//#include <bits/stdc++.h> //includes everything
#include <iostream>
#include <set>
#include <map>

using namespace std;

//Operators need to be in classes
bool operator > (int a, int b) {
	if (a > b){
		return true;
	} 
	return false;
}

int main(){
	//Ony adds one of each type - only one 5
	set<int>  s; 

	s.insert(5);

	//if doesn't find value, return set.end
	if (s.find(5) != s.end()){
		cout << "found value" << endl;
	}

	s.erase(5);

	//multisets can have more than one of each value
	multiset<int> m;

	if (m.find(5) != m.end()){
		m.erase(m.find(5));
	}

	//MAPS
	map<string, int> m2;
	m2["something"]++;

	return 0;
}
