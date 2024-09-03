/*
 * C++ Guessing Game
 * Try to guess the random number from 1-100 in the least tries possible.
 * 9/3/2024
 * Santiago Gaete
 * Class rules for C++: 1. No global variables. 2. No strings. 3. Use <iostream>
 */

#include <iostream>

using namespace std;

void invalidInput();

int main() {

  bool game = true; //know if game is active (mostly for consecutive games)
  int input = 0; //hidden number
  int guesses = 0; //# of guesses
  char input2 = 'a'; //secondary input for y/n prompts
  
  srand(time(NULL)); //random seed
  int number = (rand() % 101); //set number to rand number 1-100
  cout << "Enter a number from 0-100." << endl;
  
  while (game == true) {
    cin >> input;
    if (input < 0 || input > 100 || cin.fail()) { //if not a # 1-100, or not an integer, invalid
      invalidInput();
    }
    else if (input < number) { //too low!
      cout << "Too low!" << endl;
      guesses++;
    }
    else if (input > number) { //too high!
      cout << "Too high!" << endl;
      guesses++;
    }
    else if (input == number) { //just right
      guesses++;
      cout << "Correct! The number was " << number << ", and you won in " << guesses << " guesses." << endl;
      game = false; //end game (possibly temporarily)
      cout << "Would you like to play again? (y/n)" << endl;

      while (input == number) { //just so we can keep looping if invalid
	 cin >> input2;
	 if (input2 == 'y') { //play again
	   //reset
	   number = (rand() % 101);
	   guesses = 0;
	   cout << "Enter a number from 0-100." << endl;
	   game = true;
	 }
	 else if (input2 == 'n') { //end program
	   cout << "Bye!" << endl;
	   input = 0; //end loop
	 }
	 else { //if not y/n
	   invalidInput();
	 }
      }
    }
  }
  return 0;
}

void invalidInput() {
  cout << "Invalid input! Try again!" << endl;
  cin.clear(); //clear fail flag
  cin.ignore(10000,'\n'); //go to next line
}
