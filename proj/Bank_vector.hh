#ifndef BANK_VECTOR_HH_
#define BANK_VECTOR_HH_

#include<list>
#include<bits/stdc++.h>
#include "Account.hh"

using namespace std;

class Bank_vector
{
private:
    vector<Account *> bank_vector;
public:

    explicit Bank_vector(int money);

    Bank_vector();

    void readnmakeAccounts(istream &in);

    Account *find_Account(size_t acc);

    void append(int money);

    void deleteAccount(size_t accountNum);

    bool transfer(size_t from, size_t to, int money);

    void deposit(size_t acc, int money);

    bool withdraw(size_t acc, int money);

    int getBalance(size_t acc);

    std::string toString();

};

#endif
