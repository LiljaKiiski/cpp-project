#pragma once

#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "User.h"

using namespace std;

class Database {
	public: 
		std::string file_name;
                User user;

		Database(std::string _file_name);

		std::string read_file();
		void write_file(std::string text);
		std::string sign_in();
		std::string sign_up();
		std::string new_card();
};
