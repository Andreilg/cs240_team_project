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

Account_node* Bank_linked::find_Account(size_t _unique_ID)
{
    for (curr = head->getNext();
         curr != tail; curr = curr->getNext())
    {
        if (curr->getAccount().getAccountNum() == _unique_ID)
        {
            return curr;
        }
    }
}


//appends new bank account to the end of the list
bool Bank_linked::append(int money)
{
    tail->setNext(new Account_node());
    auto *temp = new Account(money);
    tail->setAccount(*temp);
    tail = tail->getNext();
    size++;
    std::cout<<size<<std::endl;
    return true;
}
//returns true if transfer is sucessfull, else false
bool Bank_linked::transfer(size_t from, size_t to, int money)
{
    if(size < from || size < to){
      return false;
    }
    Account_node* fromAcc = find_Account(from);
    Account_node* toAcc = find_Account(to);
    if(fromAcc->getAccount().getBalance() < money){
      return false;
    }
    else{
      fromAcc->withdraw(money);
      toAcc->deposit(money);
    }
    return true;
}

std::string Bank_linked::toString(){
    std::string ret = "";
    curr = head->getNext();
    while(curr != tail){
      ret+= curr->getAccount().toString();
      ret+= " -> ";
      curr = (curr->getNext());
    }
    ret += "NULL";
    return ret;
}

bool Bank_linked::deleteAccount(size_t acc){
  Account_node* prev;
  curr = head->getNext();
  //if first element is removed
  if(head->getNext()->getAccount().getAccountNum() == acc){
    Account_node* removed = head->getNext();
    head->setNext(removed->getNext());
    free(removed);
    size -=1;
    return true;
  }
  while(curr->getAccount().getAccountNum() <= acc){
    if(curr->getAccount().getAccountNum() == acc){
      prev->setNext(curr->getNext());
      free(curr);
      size-=1;
      return true;
    }
    prev = curr;
    curr = curr->getNext();
  }

  return false;
}

int main(){
  Bank_linked test;
  test.append(5);
  test.append(6);
  test.append(7);
  std::cout<<test.toString()<<std::endl;
  std::cout<< test.deleteAccount(1) <<std::endl;
  std::cout<< test.deleteAccount(2) <<std::endl;
  std::cout<< test.deleteAccount(3) <<std::endl;
  std::cout<<test.toString()<<std::endl;
  return 0;
}
