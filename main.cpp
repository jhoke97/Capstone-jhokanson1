#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "account.h"

using namespace std;
bool doesExist(char*);
void createAccount(char*, string);
double getBalance(char*);
bool passwordCheck(char*, string);
double stringToDouble(string);
void closeAccount(char*, double, string);
int main()
{
  account activeAccount;
  string option, password, password2; 
  char username[100];
  double transaction;
  bool validOption = true;
  cout << "Welcome to the bank of CSCI111.\n";
  do{
    cout << "[C]reate Account\n";
    cout << "[A]ccess Account\n";
    cout << "[E]xit\n";
    cin >> option;
    if(option == "E" || option == "e")
    {
      cout << "Goodbye!" << endl; 
      return 0;
    }else if(option == "C" || option == "c")
    {
      cout << "CREATE NEW ACCOUNT\n";
      cout << "Enter new username: ";
      cin >> username;
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
    }else if(option == "A" || option == "a")
    {
      cout << "Enter Username: ";
      cin >> username;
      cout << endl << "Enter password: ";
      cin >> password;
      if(doesExist(username))
      {

        if(passwordCheck(username, password))
        {
          activeAccount.setUsername(username);
          double balanceToGet = getBalance(username); 
          cout << balanceToGet << endl; 
          activeAccount.setBalance(balanceToGet); 
        }else
        {
          while(passwordCheck(username, password) == false)
          {
            cout << "Re-enter password or type -1 to exit\n"; 
            cin >> password;
            cout << endl << password << endl;
            if(password == "-1")
            {
              return 0;
            }
          }
        validOption = true; 
        }
      }else
      {
        cout << "Account Does Not Exist. Exiting.\n";
        return 0; 
      }
    }else
    {
      cout << "Inalid input, try again\n";
      validOption = false; 
    }
  }
  while(!validOption);
  cout << endl << "Welcome " << username << endl;
  while(true)
  {
    cout << endl << "What would you like to do?" << endl;
    cout << "[D]eposit Money" << endl;
    cout << "[W]ithdraw Money" << endl;
    cout << "[V]iew Balance" << endl;
    cout << "[E]xit" << endl; 
    cin >> option;
    if(option == "D" || option == "d")
    {
      cout << "Amount to deposit: ";
      cin >> transaction;
      activeAccount.makeDeposit(transaction); 
      cout << endl << transaction << " dollars deposited\n";
    }else if(option == "W" || option == "w")
    {
      cout << "Amount to withdraw: ";
      cin >> transaction;
      if(activeAccount.isEnough(transaction))
      {
        activeAccount.makeWithdrawl(transaction);
        cout << endl << transaction << " dollars withdrawn\n";
      }else{
        cout << "Insufficient funds" << endl;
      }
    }else if(option == "V" || option == "v")
    {
      cout << endl << "Account Balance: " << activeAccount.getBalance() << endl;

    }else if(option == "E" || option == "e")
    {
      double saveBalance = activeAccount.getBalance();
      closeAccount(username, saveBalance, password);
      return 0; 
    }
  }
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
    return true;
  }else{
    return false; 
  }
}
void createAccount(char* username, string password)
{
  ofstream file;
  file.open(username);
  file << password << endl;
  file << 0;
  file.close(); 
  cout << "Account Created" << endl; 

}
double getBalance(char* username)
{
  string garbage; 
  string balance; 
  ifstream read;
  read.open(username);
  getline(read, garbage);
  getline(read, balance);
  double balanceToReturn = stringToDouble(balance);
  return balanceToReturn;
}
double stringToDouble(string toConvert)
{
  double doubleToReturn = atof(toConvert.c_str()); 
  return doubleToReturn;
}
void closeAccount(char* username, double balance, string password)
{
  ofstream write;
  remove(username);
  write.open(username);
  write << password << endl;
  write << balance;
  write.close();
}
bool doesExist(char* username)
{
  fstream file;
  file.open(username);
  if(file.is_open())
  {
    return true;
  }else
  {
    return false;
  }
}
