#include "Bank_linked.hh"

/*Bank_linked::Bank_linked(int money) :
        acc(new Account(money)), next(nullptr), prev(nullptr)
{}

Account *Bank_linked::readUserInfo(std::istream &in)
{
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
    if (head == nullptr)
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
    bank_linked->next = nullptr;
    return bank_linked;
}*/

/*Bank_linked::Bank_linked() :
        tail(new Account_node(nullptr)), curr(tail),
        head(new Account_node(this->tail)), size(0)
{}*/
Bank_linked::Bank_linked()
{
    curr = tail = new Account_node();
    head = new Account_node();
    head->setNext(tail);
    size = 0;
}

Account Bank_linked::find_Account(size_t _unique_ID)
{
    for (curr = head->getNext();
         curr != tail; curr->setNext(curr->getNext()->getNext()))
    {
        if (curr->getAccount().getAccountNum() == _unique_ID)
        {
            return curr->getAccount();
        }
    }
}


bool Bank_linked::append(int money)
{
    tail->setNext(new Account_node());
    auto *temp = new Account(money);
    tail->setAccount(*temp);
    size++;
    return true;
}

std::string Bank_linked::toString(){
    std::string ret = "";
    for(curr = head->getNext(); curr != tail; curr->setNext(curr->getNext())){
      ret+= curr->getAccount().toString();
      ret+= "-> ";
    }
    ret += "NULL";
    return ret;
}

int main(){

  return 0;
}
