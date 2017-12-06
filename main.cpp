#include <iostream>
#include <string>
#include <fstream>
#include "account.h"

using namespace std;

void createAccount(char*, string);
void openAccount(char*, string);
bool passwordCheck(char*, string);
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
  string option, password, password2; 
  char username[100];
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
//      cin.getline(username, 100); 
      cout << endl << "Enter your password: ";
      cin >> password;
      cout << endl << "Confirm password: ";
      cin >> password2;
      if(password == password2)  
      {
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
        createAccount(username, password); 
        validOption = true;
      }
    }else if(option == "O" || option == "o")
    {
      cout << "Enter Username: ";
      cin >> username;
      cout << endl << "Enter password: ";
      cin >> password;
      if(passwordCheck(username, password))
      {
      openAccount(username, password);
      }
      validOption = true;
    }else
    {
      cout << "Inalid input, try again\n";
      validOption = false; 
    }
  }
  while(!validOption);
  return 0;
}
bool passwordCheck(char* username, string password)
{
  string passwordToCompare;
  ifstream file;
  file.open(username);
  getline(file, passwordToCompare);
  if(password == passwordToCompare)
  {
    cout << "Welcome " << username << endl;
    return true;
  }else{
    cout << "Password does not match username\n";
  }
  }
void createAccount(char* username, string password)
{
  cout << "Creating account..." << endl; 
  ofstream file;
  file.open(username);
  file << password << endl;
  file << 0;
  file.close(); 
}
void openAccount(char* username, string password)
{
  string passwordToCompare;
  ifstream read; 
  read.open(username);
  getline(read, passwordToCompare); 
  
}
