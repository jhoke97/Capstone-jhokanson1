#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class account
{
  private:
    double balance;
    std::string username;
  public:
    void setBalance(double);
    void setUsername(char[100]);
    void makeDeposit(double);
    void makeWithdrawl(double);
    double getBalance();
    account();
};

#endif
