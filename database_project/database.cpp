#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "User.h"

using namespace std;
using namespace rapidjson;

//Global variables
const string file_name = "pokebase.json";
User user;

//Global methods
string read_file();
void write_file(string text);
string sign_in();
string sign_up();
string new_card();

//Main method
int main(){
	//Update user's document        
        user.set_document(read_file());

	//Welcome menu
	cout <<"+----------------------------------------------------+"<<endl;
	cout <<"|       WELCOME TO THE AMAZING POKÉ-DATABASE!        |"<<endl; 
        cout <<"+----------------------------------------------------+"<<endl;

	string choice = "0";
        while (choice != "1" && choice != "2"){
		cout <<"+----------------------------------------------------+"<<endl;
               	cout <<"|Select: (1) Sign In, or (2) Sign Up:                |"<<endl;
               	cout <<"+----------------------------------------------------+"<<endl;
		cout <<">> ";
               	cin >> choice;
        }

	//Set username based on Sign in/ Sign up
       	choice == "1" ? user.set_username(sign_in()) : user.set_username(sign_up());
	
	//Update file and user's doc
        write_file(user.get_json_txt());
	user.set_document(read_file());

	//Main menu
        cout <<"Welcome to your account, " + user.username<<endl;
	while (true) {
		choice = "0";
		while (choice != "1" && choice != "2" && choice != "3"){
              		cout <<"+----------------------------------------------------+"<<endl;
                	cout <<"|Select: (1) View Cards, (2) Add Cards, or (3) Exit: |"<<endl;
                	cout <<"+----------------------------------------------------+"<<endl;
                	cout <<">> ";
                	cin >> choice;
        	}
	
		//View cards
		if (choice == "1"){
			cout <<"Here are your cards, " + user.username<<endl;
                        cout <<"CARD : QUANTITY"<<endl;			
			user.show_cards();
		
		//Add cards
		} else if (choice == "2"){
			cout <<"You got 3 Mystery Cards!"<<endl;
			string cards[] = {new_card(), new_card(), new_card()};

			//Show cards
        		for (int x = 0; x <= 2; x++){ 
				cout <<"CARD " + to_string(x+1) + ": " + cards[x]<<endl;
			}

			//Update cards
			user.update_cards(2, cards);

			//Update file
			write_file(user.get_json_txt());
		
		//Exit
		} else {
                        cout <<"Goodbye, " + user.username<<endl;
                        break;
                }
	}
        return 0;
}

//Reads JSON file AND updates document
string read_file(){
	string json;
        ifstream fint(file_name);
        fint >> json;

	return json;
}

//Writes to JSON file
void write_file(string text){
	ofstream fout(file_name);
	fout << text << endl;
}

//Signs in existing user
string sign_in(){	
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
string sign_up(){
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
string new_card(){
	string possibles[] {"pikachu", "tyranitar", "moltres", "bulbasaur", "litten"};

        return possibles[rand() % 5];
}
