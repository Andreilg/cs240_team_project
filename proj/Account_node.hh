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
    Account_node();

    Account_node(int _money, Account_node *_next);

    Account getElement();

    void setElement(Account _acc);

    Account_node *getNext();

    void *setNext(Account_node *_next);
};

#endif //PROJ_ACCOUNT_NODE_HH
