#ifndef PROJ_ACCOUNT_NODE_HH
#define PROJ_ACCOUNT_NODE_HH

#include <cstddef>
#include "Account.hh"

class Account_node
{
private:
    Account acc;
    Account_node *next;
public:
    Account_node(int money, Account_node *next);

    Account_node(Account_node *next);

    Account element();

    Account setElement(Account _acc);

    Account_node *next_node();

    Account_node *setNext(Account_node *_next);
};

#endif //PROJ_ACCOUNT_NODE_HH
