#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class User {
	public:
		std::string username;
		rapidjson::Document d;

		User();

		void set_document(std::string json);

		void set_username(std::string _username);

		void show_cards();

		void update_cards(int length, std::string cards[]);

		std::string get_json_txt();
};
