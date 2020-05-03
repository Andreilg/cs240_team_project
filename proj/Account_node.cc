#include "Account_node.hh"


Account_node::Account_node() :
        acc(-1), next(nullptr)
{}

Account_node::Account_node(int _money, Account_node *_next) :
        acc(_money), next(_next)
{}

Account Account_node::getAccount()
{
    return acc;
}

void Account_node::setAccount(Account _acc)
{
    acc = _acc;
}

Account_node *Account_node::getNext()
{
    return next;
}

void *Account_node::setNext(Account_node *_next)
{
    next = _next;
}
