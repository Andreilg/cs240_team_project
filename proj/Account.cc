# include "Account.hh"

size_t unique_num = 1;

Account::Account(int money) :
        unique_ID(unique_num), money(money)
{
  if(money != -1){
    unique_num++;
  }
}

/*// Return next account read from in, Return nullptr on EOF
std::unique_ptr<Account> Account::read(std::istream &in)
{
    size_t unique;
    if (!(in >> unique)) return nullptr;
    int money;
    if (!(in >> money))
    {
        return std::make_unique<Account>(unique);
    }
    return std::make_unique<Account>(unique, money);
}*/

size_t Account::getAccountNum() const
{
    return this->unique_ID;
}

int Account::getBalance() const
{
    return this->money;
}

void Account::depositMoney(int moneyIn)
{
    this->money += moneyIn;
    std::cout << "Your current balance :: " << this->money << std::endl;
}

void Account::withdrawMoney(int moneyOut)
{
    if ((this->money - moneyOut) >= 0)
    {
        this->money -= moneyOut;
        std::cout << "Money deposited successfully" << std::endl;
        std::cout << "Your current balance :: " << this->money << std::endl;
    }
    else
    {
        std::cout << "You cannot withdraw that amount of money, "
                     "the value is greater than your balance" << std::endl;
        std::cout << "Your current balance :: " << this->money << std::endl;
    }
}

std::string Account::toString() const
{
    return "account number :: " + std::to_string(this->unique_ID) + " deposit money value :: " +
           std::to_string(this->money);
}

/*int main(){
  Account test(1);
  std::cout<<sizeof(test)<<std::endl;
  Account test2(2);
  Account arr[] = {test,test2};
  std::cout<<sizeof(arr)<<std::endl;
  return 0;
}*/
