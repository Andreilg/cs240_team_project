#ifndef ACCOUNT_HH_
#define ACCOUNT_HH_

#include<memory>
#include<iostream>
#include<string>

class Account{
public:
	uint64_t unique;
	signed int money;

Account(uint64_t unique, int money);
Account(uint64_t unique);
std::string toString() const;

static std::unique_ptr<Account> read(std::istream & in);

int depositValue();

uint64_t accountNum();

void depositMoney(int moneyIn);

void withdrawMoney(int moneyOut);

};

#endif