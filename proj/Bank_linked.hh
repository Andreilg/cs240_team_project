#ifndef ACCOUNT_HH_
#define BANK_HH_

#include <list>
#include "Account.hh"
#include "Account_node.hh"

class Bank_linked
{
private:
    Account_node *curr;
    Account_node *tail;
    Account_node *head;
    int size;
public:
    Bank_linked();

    Account find_Account(size_t _unique_ID);

    bool append(int money);
    std::string toString();
};

#endif
