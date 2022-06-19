#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	ifstream fint("/usr/share/dict/words");
	ofstream fout("words.txt");

	//String being read
        string s;

	//Until s reaches last letter
        while(s != "zoos") {
                fint >> s;

		//If doesn't include commas, and is 5 letters
		if (s.find('\'') == string::npos && s.length() == 5){
			//Make uppercase
			transform(s.begin(), s.end(), s.begin(), ::toupper);
			
			//Write
			fout << s << endl;
		}
        }

        return 0;
}
