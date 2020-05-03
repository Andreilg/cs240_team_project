#ifndef ACCOUNT_HH_
#define BANK_HH_

#include<list>
#include "Account.hh"
#include "Account_node.hh"

class Bank_linked
{
private:
    Account_node *curr = new Account_node();
    Account_node *tail = curr;
    Account_node *head = new Account_node(tail);
    int size = 0;
public:
    Bank_linked();

    bool insert(int money)
    {
        curr.setNext(new Account_node(money, curr.next_node()));
    }

    bool append(int money)
    {
        tail.setNext(new Account_node(nullptr));
        auto *temp = new Account(money);
        tail.setElement(*temp);
        tail = tail.next_node();
        size++;
        return true;
    }
};

#endif
