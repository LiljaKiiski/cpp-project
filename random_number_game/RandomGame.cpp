#include <iostream>

int main(){
  using namespace std;

  //Game welcome message
  cout <<"Hi! Welcome to the guessing game!\n\n";
  cout <<"I chose a number from 1 to 100, can you guess it?\n";

  //Creates random number
  srand(time(NULL));
  int randomNum = rand() % 100 + 1;
  
  int number = 0;
  int tries = 1;
  cin >> number;
  
  //Keep playing until player has guessed number
  while (number != randomNum){
    tries++;
    if (number < randomNum){
      cout << "That's too low, try again!\n";
       cin >> number;
    } else if (number > randomNum){
      cout << "That's too high, try again!\n";
       cin >> number;
    }
  }

  //You win message
  cout << "You got it!\n";
  cout << "It took you " + to_string(tries) + " tries\n";
}