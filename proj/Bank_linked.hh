#ifndef ACCOUNT_HH_
#define BANK_HH_

#include<list>

#include "Account.hh"
class Bank_linked{
public:
	Account * acc;
	Bank_linked * next;
	
Bank_linked();

Account* readUserInfo(std::istream& in);
Bank_linked* createBank_linked(Bank_linked* head,Account *acc);
void transfer(uint64_t from, uint64_t to, int money);
std::string showAccount(uint64_t accountNum);
Bank_linked* newAccount(Account* acc);

};

#endif
