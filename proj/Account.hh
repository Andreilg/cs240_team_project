#ifndef ACCOUNT_HH_
#define ACCOUNT_HH_

#include<memory>
#include<iostream>
#include<string>

class Account
{
public:
    size_t unique;
    signed int money;

    Account(size_t unique, int money);

    Account(size_t unique);

    std::string toString() const;

    static std::unique_ptr<Account> read(std::istream &in);

    int depositValue();

    size_t accountNum();

    void depositMoney(int moneyIn);

    void withdrawMoney(int moneyOut);

};

#endif