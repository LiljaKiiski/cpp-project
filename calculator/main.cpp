#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void calculate(string s);
void mult_div();
void add_sub();
void string_to_vectors(string);
bool in_array(string, vector<string>);

//Global variables
vector<string> numbers;
vector<string> operations;

int main(){
	while (true){
		numbers.clear();
		operations.clear();

		string input = "";

		cout << "Math equation: ";
		cin >> input;

		calculate(input);
	}
	return 0;
}

void calculate(string s){
	//Add zero to numbers
	numbers.push_back("0");

	//Convert string input to vectors of numbers and operations
	string_to_vectors(s);	

	//Calculate in order
	mult_div();
	add_sub();

	//Print out results
	cout << numbers[0] << endl;
}

//First do multiplication and division
void mult_div(){	
	int x = 0;
	while (in_array("*", operations) || in_array("/", operations)){
                double num1 = stod(numbers.at(x));
               	double num2 = stod(numbers.at(x+1));
                double result = 0;

                if (operations.at(x) == "*"){
			result = num1 * num2;
                        numbers.at(x) = to_string(result);
                        operations.erase(operations.begin() + x);
                        numbers.erase(numbers.begin() + x+1);
                
		} else if(operations.at(x) == "/"){
			result = num1 / num2;
                        numbers.at(x) = to_string(result);
                        operations.erase(operations.begin() + x);
                        numbers.erase(numbers.begin() + x+1);
                
		} else {
			x++;
		}
        }
}

//Next do addition and subtraction
void add_sub(){
        int x = 0;
        while (in_array("+", operations) || in_array("-", operations)){
                double num1 = stod(numbers.at(x));
                double num2 = stod(numbers.at(x+1));
                double result = 0;

                if (operations.at(x) == "+"){
                        result = num1 + num2;
                        numbers.at(x) = to_string(result);            
			operations.erase(operations.begin() + x);	
			numbers.erase(numbers.begin() + x+1);

                } else if(operations.at(x) == "-"){
                        result = num1 - num2;
                        numbers.at(x) = to_string(result);
                        operations.erase(operations.begin() + x);
                        numbers.erase(numbers.begin() + x+1);
                
		} else {
			x++;
		}
        }
}

//Organize array into numbers and operations
void string_to_vectors(string s){
	for (int x = 0; x < s.length(); x++){
		string at(1, s[x]);

		try { //is valid number or decimal
			if (at == "."){ //is decimal place
				string old = numbers.at(numbers.size()-1);
                        	numbers.at(numbers.size()-1) = old + ".";	
			} else {
				int i = stod(at);

				string old = numbers.at(numbers.size()-1);
				numbers.at(numbers.size()-1) = old + to_string(i);
			}
		} catch (invalid_argument e){ //is operation
			operations.push_back(at);
			numbers.push_back("0");
		}
	}
}

//Checks if value is in vector
bool in_array(string value, vector<string> array){
    return find(array.begin(), array.end(), value) != array.end();
}
