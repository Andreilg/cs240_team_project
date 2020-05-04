#include "Bank_linked.hh"

Bank_linked::Bank_linked()
{
    curr = tail = new Account_node();
    head = new Account_node();
    head->setNext(tail);
    size = 0;
}

Account_node *Bank_linked::find_Account(size_t _unique_ID)
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

int Bank_linked::getBalance(size_t num){
  Account_node* acct = find_Account(num);
  return acct->getAccount().getBalance();
}



bool Bank_linked::withdraw(size_t num, int money){
  if(getBalance(num) < money ){
    return false;
  }
  else{
    Account_node* acct = find_Account(num);
    acct->withdraw(money);
    return true;
  }

}

void Bank_linked::deposit(size_t num, int money){
  Account_node* acct = find_Account(num);
  acct->deposit(money);
}

//appends new bank account to the end of the list
bool Bank_linked::append(int money)
{
    tail->setNext(new Account_node());
    auto *temp = new Account(money);
    tail->setAccount(*temp);
    tail = tail->getNext();
    size++;
    return true;
}

//returns true if transfer is sucessfull, else false
bool Bank_linked::transfer(size_t from, size_t to, int money)
{
    if (size < from || size < to)
    {
        return false;
    }
    if(withdraw(from,money) == false){
      return false;
    }
    else{
      deposit(to,money);
      return true;
    }
}

std::string Bank_linked::toString()
{
    std::string ret = "";
    curr = head->getNext();
    while (curr != tail)
    {
        ret += curr->getAccount().toString();
        ret += " -> ";
        curr = (curr->getNext());
    }
    ret += "NULL";
    return ret;
}

bool Bank_linked::deleteAccount(size_t acc)
{
    Account_node *prev;
    curr = head->getNext();
    //if first element is removed
    if (head->getNext()->getAccount().getAccountNum() == acc)
    {
        Account_node *removed = head->getNext();
        head->setNext(removed->getNext());
        free(removed);
        size -= 1;
        return true;
    }
    while (curr->getAccount().getAccountNum() <= acc)
    {
        if (curr->getAccount().getAccountNum() == acc)
        {
            prev->setNext(curr->getNext());
            free(curr);
            size -= 1;
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
  std::cout<<sizeof(Bank_linked)<<std::endl;
  return 0;
}
