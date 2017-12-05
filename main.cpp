#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void createAccount();
int main()
{
  /*
     withdraw
     deposit
     view balance
     print receipt
     change account
     open account 
     close session
     */
  account activeAccount;
  string option, username, password, password2; 
  bool validOption = true;
  cout << "Welcome to the bank of CSCI111.\n";
  do{
    cout << "[C]reate Account\n";
    cout << "[O]pen Accoubt\n";
    cout << "[E]xit\n";
    cin >> option;
    if(option == "E" || option == "e")
    {
      return 0;
    }else if(option == "C" || option == "c")
    {
      cout << "CREATE NEW ACCOUNT\n";
      cout << "Enter new username: ";
      cin >> username;
      cout << endl << "Enter password: ";
      cin >>password;
      cout << endl << "Confirm password: "
        cin >> password2;
      if(password == password2)
      {
        cout << "Creating Account...\n";
        createAccount(username, password);
      }else
      {
        while(password != password2)
        {
          cout << "Passwords do not match. Please re-enter password\n";
          cout << "Password: ";
          cin >> password;
          cout << endl << "Confirm password: ";
          cin >> password2;
        }
        cout << "Creating Account...\n" 
        createAccount(username, password); 
        validOption = true;
      }
    }else if(option == "O" || option == "o")
    {
      //      openAccount();
      validOption = true;
    }else
    {
      cout << "Inalid input, try again\n";
      validOption = false; 
    }
  }
  while(!validOption);
}

void createAccount(string username, string password)
{
  ofstream file;
  file.open(username);
  file << password;
  file.close(); 
}

