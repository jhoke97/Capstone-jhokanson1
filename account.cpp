#include "account.h"
#include <string>
account::account()
{
  balance = 0.00;
  username = " ";
}

void account::setBalance(double money)
{
  balance = balance + money;
}

void account::setUsername(char userName[100])
{
  username = userName;
}
void account::makeDeposit(double transaction)
{
  balance = balance + transaction;
}
void account::makeWithdrawl(double transaction)
{
  balance = balance - transaction;
}
double account::getBalance()
 {
   return balance;
 }

