#ifndef ACCOUNT_HH_
#define BANK_HH_

#include<list>
#include<bits/stdc++.h>
#include "Account.hh"
using namespace std; 

class Bank_vector{
private:
	vector<Account*> bank_vector;
public:
	
Bank_vector(int money);
void readnmakeAccounts(istream& in);
Account* findAccount(size_t acc);
void addAccount(int money);
void deleteAccount(size_t accountNum);
void transfer(size_t from, size_t to, int money);
std::string toString();

};

#endif