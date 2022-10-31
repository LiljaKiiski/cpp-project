#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "User.h"
#include "Database.h"

using namespace std;
using namespace rapidjson;

//Main method
int main(){
	//Create new document
	Database base("pokebase.json");

	//Update user's document        
        base.user.set_document(base.read_file());

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
       	choice == "1" ? base.user.set_username(base.sign_in()) : base.user.set_username(base.sign_up());
	
	//Update file and user's doc
        base.write_file(base.user.get_json_txt());
	base.user.set_document(base.read_file());

	//Main menu
        cout <<"Welcome to your account, " + base.user.username<<endl;
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
			cout <<"Here are your cards, " + base.user.username<<endl;
                        cout <<"CARD : QUANTITY"<<endl;			
			base.user.show_cards();
		
		//Add cards
		} else if (choice == "2"){
			cout <<"You got 3 Mystery Cards!"<<endl;
			string cards[] = {base.new_card(), base.new_card(), base.new_card()};

			//Show cards
        		for (int x = 0; x <= 2; x++){ 
				cout <<"CARD " + to_string(x+1) + ": " + cards[x]<<endl;
			}

			//Update cards
			base.user.update_cards(2, cards);

			//Update file
			base.write_file(base.user.get_json_txt());
		
		//Exit
		} else {
                        cout <<"Goodbye, " + base.user.username<<endl;
                        break;
                }
	}
        return 0;
}

