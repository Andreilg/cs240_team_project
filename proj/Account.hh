#ifndef ACCOUNT_HH_
#define ACCOUNT_HH_

#include<memory>
#include<iostream>
#include<string>

extern size_t unique_num;

class Account
{
private:
    size_t unique_ID;
    int money;
public:
    explicit Account(int money);

    //static std::unique_ptr<Account> read(std::istream &in);

    [[nodiscard]] size_t getAccountNum() const;

    [[nodiscard]] int getBalance() const;

    void depositMoney(int moneyIn);

    void withdrawMoney(int moneyOut);

    [[nodiscard]] std::string toString() const;
};

#endif
