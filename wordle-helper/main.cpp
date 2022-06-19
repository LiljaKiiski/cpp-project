#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct Word {
	string word;
	string colors;
};

const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string CYAN = "\033[0;36m";
const string MAGENTA = "\033[0;35m";
const string RESET = "\033[0m";

void print_current(string, string);
void print_possibles(vector<string> possibles);
vector<string> get_possibles(vector<string>, Word);
vector<string> get_all_words();

int main(){
	vector<Word> words;
        vector<string> possible_words = get_all_words();
	cout << "Welcome to Wordle Helper\n" << endl;

        for (int x = 0; x < 5; x++){
                Word word;
                cout << "Word " + to_string(x+1) + ": ";
                cin >> word.word;

                string colors;
                cout << "Colors: ";
                cin >> word.colors;

		transform(word.word.begin(), word.word.end(), word.word.begin(), ::toupper);
		transform(word.colors.begin(), word.colors.end(), word.colors.begin(), ::toupper);

                words.push_back(word);
                print_current(word.word, word.colors);

		possible_words = get_possibles(possible_words, word);
		print_possibles(possible_words);
        }

	return 0;
}

vector<string> get_possibles(vector<string> possible_words, Word word){
	vector<string> possibles;
	
	for (int x = 0; x < possible_words.size(); x++){

		for (int y = 0; y < word.word.length(); y++){
			string s = possible_words[x];

			//Green letters don't match
			if ( (word.colors[y] == 'G' && word.word[y] != s[y]) ||

				//Yellow letter is not in string or in same location
				(word.colors[y] == 'Y' && (s.find(word.word[y]) == -1 || s.find(word.word[y]) == y)) ||

				//Black letter is in string	
				(word.colors[y] == 'B' && s.find(word.word[y]) != -1) ){
					
					break;
			}

			if (y == word.word.length()-1){
				possibles.push_back(s);
			}
		}
	}
	return possibles;
}

vector<string> get_all_words(){
	vector<string> all_words;
	ifstream fint("words.txt");
	string s;

	while(s != "ZOOMS") {
        	fint >> s;
		all_words.push_back(s);
	}

	return all_words;
}

void print_possibles(vector<string> possibles){
	cout << "POSSIBLE WORDS: " << endl;
	for (int x = 0; x < possibles.size(); x++){
		cout << to_string(x+1) << " - " << possibles[x] << endl;
	}
}

void print_current(string word, string colors){
	for (int x = 0; x < 5; x++){
		if (toupper(colors[x]) == 'G'){
                       	cout << GREEN << "[" << string(1, word[x]) << "]" << RESET;

               	} else if (toupper(colors[x]) == 'Y'){
               	        cout << YELLOW << "[" << string(1, word[x]) << "]" << RESET;

		} else {
                       	cout << CYAN << "[" << string(1, word[x]) << "]" << RESET;
               	}

	}
	cout << "\n";
}
