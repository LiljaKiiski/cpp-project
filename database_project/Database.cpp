#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "User.h"
#include "Database.h"

using namespace std;
using namespace rapidjson;

//Constructor
Database::Database(string _file_name){
	file_name = _file_name;
}

//Reads JSON file AND updates document
string Database::read_file(){
	string json;
	ifstream fint(file_name);
	fint >> json;

	return json;
}

//Writes to JSON file
void Database::write_file(string text){
	ofstream fout(file_name);
	fout << text << endl;
}

//Signs in existing user
string Database::sign_in(){
	string username;
	cout <<"USERNAME >> ";
	cin >> username;

	while (!user.d.HasMember(username.c_str())){ //While username doesn't exist
		cout <<"Sorry, that account doesn't exist"<<endl;
		cout <<"USERNAME >> ";
		cin >> username;
	}
	return username;
}

//Sign up new user
string Database::sign_up(){
	string username;
	cout <<"CREATE USERNAME >> ";
	cin >> username;

	while (user.d.HasMember(username.c_str())){ //While username exists
		cout <<"Sorry, that username already exists"<<endl;
		cout <<"CREATE USERNAME >> ";
		cin >> username;
	}
	return username;
}

//Return random card
string Database::new_card(){
	string possibles[] {"pikachu", "tyranitar", "moltres", "bulbasaur", "litten"};

	return possibles[rand() % 5];
}
