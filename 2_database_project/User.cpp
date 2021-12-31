#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "User.h"

using namespace std;
using namespace rapidjson;

//Constructor
User::User(){
	//Set random
	srand(time(NULL));

	//Set to object
	d.SetObject();
}

//Set document
void User::set_document(string json){
	d.Parse(json.c_str());
}

//Set username
void User::set_username(string _username){
       	username = _username;

       	//Add new user to doc if none exist
        if (!d.HasMember(username.c_str())){
		Value name(username.c_str(), username.length(), d.GetAllocator());
                Value items(kArrayType);
               	d.AddMember(name, items, d.GetAllocator());
        }
}

//Prints cards
void User::show_cards(){
	const Value& value = d[username.c_str()];
       	for (int x = 0; x < value.Size(); x++){
              	const Value& obj = value[x];

               	for (Value::ConstMemberIterator it = obj.MemberBegin(); it != obj.MemberEnd(); it++) {
               	       	cout << it->name.GetString() << " : " << it->value.GetInt()<< endl;
               	}
        }
}

//Updates cards to doc
void User::update_cards(int length, string cards[]){
	for (int x = 0; x <= length; x++){
		Value& value = d[username.c_str()];
		bool exists = false;
		string card = cards[x];

		//Loop through values checking if card exists
	        for (int x = 0; x < value.Size(); x++){
			//Card exists - increase quantity
			if (value[x].HasMember(card.c_str())){
                      		int num = value[x][card.c_str()].GetInt();
                       		num++;
                       		value[x][card.c_str()] = num;
                       		exists = true;
				break;
                	}
        	}

		//Card doesn't exist - add new
        	if (!exists){
			Value name(cards[x].c_str(), cards[x].length(), d.GetAllocator());
                        Value items(kObjectType);
                        items.AddMember(name, 1, d.GetAllocator());
                       	d[username.c_str()].PushBack(items, d.GetAllocator());
		}
	}
}


//Returns json text for writing to file
string User::get_json_txt(){
	StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        d.Accept(writer);

        return buffer.GetString();
}

