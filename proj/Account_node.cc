#include "Account_node.hh"


Account_node::Account_node(Account_node *next) :
        acc(-1), next(next)
{}

Account_node::Account_node(int money, Account_node *next) :
        acc(money), next(next)
{}

Account Account_node::element()
{
    return this->acc;
}

Account Account_node::setElement(Account _acc)
{
    return this->acc = _acc;
}

Account_node *Account_node::next_node()
{
    return this->next;
}

Account_node *Account_node::setNext(Account_node *_next)
{
    return this->next = _next;
}
