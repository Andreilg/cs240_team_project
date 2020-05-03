#include "Bank_linked.hh"

Bank_linked::Bank_linked() :
        acc(), next(NULL)
{}


Account *Bank_linked::readUserInfo(std::istream &in)
{

    Account *acc = new Account(0, 0);
    size_t account;
    if (!(in >> account)) return nullptr;
    int money;
    if (!(in >> money))
    {
        acc->unique = account;
        return acc;
    }
    acc->unique = account;
    acc->money = money;
    return acc;
}


Bank_linked *Bank_linked::createBank_linked(Bank_linked *head, Account *acc)
{
    if (head == NULL)
    {
        return newAccount(acc);
    }
    else
    {
        head->next = createBank_linked(head->next, acc);
        return head;
    }

    //todo
}

//transfer money from(account) to(account)
void Bank_linked::transfer(size_t from, size_t to, int money)
{
    //todo

}


std::string Bank_linked::showAccount(size_t accountNum)
{
    Account account(0, 0);
    //searching algorithm
    return "your account has " + std::to_string(account.money) + " dollor right now";
}

Bank_linked *Bank_linked::newAccount(Account *acc)
{
    Bank_linked *bank_linked = new Bank_linked;
    bank_linked->acc = acc;
    bank_linked->next = NULL;
    return bank_linked;
}

