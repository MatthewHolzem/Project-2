// Matthew Holzem CPSC 120 Section 0-8

#include <iostream>
using namespace std;

float deposit_cash;
string yes_or_no;
string user_choice;
const int PIN = 7890;
int main(int argc, char* argv[]) {

  int user_pin;
  string first_arg = argv[1];
  int pin = std::stoi( first_arg );
  string second_arg = argv[2];
  int balance = std::stoi( second_arg );



  if ( pin != 7890 || balance != 1000 ) {
    cout << "This account does not exist" << endl;
    cout << "Try again another time" << endl;
    return 0;
  }
  else if ( pin == 7890 && balance == 1000 ) {
    cout << "Welcome to branch 120 at CPSC bank" << endl;
    cout << "Please enter PIN" << endl;
  }

  cin >> user_pin;

  if ( PIN != user_pin ) {
    cout << "Pin is not correct" << endl;
    return 0;
  }
  else if ( PIN == user_pin ) {
    cout << "What would you like to do today?" << endl;
  }

  label_atmstart:
  cout << "1- Check Balance" << endl;
  cout << "2- Deposit Cash" << endl;
  cout << "3- Withdraw Cash" << endl;
  cout << "4- Exit" << endl;

cin >> user_choice;

  if ( user_choice == "1" ) {
    cout << "Your balance is: $" << balance << endl;
    cout << "What would you like to do now" << endl;
    goto label_atmstart;
  }
  else if ( user_choice == "2" ) {
  cout << "Enter the amount you want to deposit" << endl;
  cin >> deposit_cash;
  balance = balance + deposit_cash;
  cout << "Thank you" << endl;
  cout << "Your new balance is: $" << balance << endl;
  cout << "What would you like to do now" << endl;
  goto label_atmstart;
  }
  else if ( user_choice == "3" ) {
    cout << "How much do you want to withdraw" << endl;
    cin >> deposit_cash;
    if ( deposit_cash <= balance) {
      balance = balance - deposit_cash;
      goto label_atmstart;
  }
  else if ( deposit_cash > balance ) {
    cout << "Not enough funds" << endl;
    cout << "Would you like to withdraw $" << balance << " instead (y/n)" << endl;
    cin >> yes_or_no;
    if ( yes_or_no == "y" ) {
      balance = balance - balance;
      cout << "Thank you" << endl;
      cout << "Your new balance is: $" << balance << endl;
    }
    else if ( yes_or_no == "n") {
      goto label_atmstart;
    }
  }
  cout << "What would you like to do next" << endl;
  goto label_atmstart;
}
  else if ( user_choice == "4" ) {
    cout << "Goodbye" << endl;
    return 0;
  }
}
