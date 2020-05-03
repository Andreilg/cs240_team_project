# include "Account.hh"

Account::Account(uint64_t unique, int money) :
	unique(unique), money(money){}
Account::Account(uint64_t unique) :
	unique(unique), money(100){}
	
// Return next account read from in, Return nullptr on EOF
std::unique_ptr<Account> Account::read(std::istream& in){
	uint64_t unique;
	if(!(in>>unique)) return nullptr;
	int money;
	if(!(in>>money)){
		return std::make_unique<Account>(unique);
	}
	return std::make_unique<Account>(unique,money);
}

int Account::depositValue(){
	return money;
}

uint64_t Account::accountNum(){
	return unique;
}

void Account::depositMoney(int moneyIn){
	money += moneyIn;
	std::cout<<"your current value :: " << money << std::endl;
}

void Account::withdrawMoney(int moneyOut){
	if((money - moneyOut) > 0){
		money -= moneyOut;
		std::cout<<"Money deposit successfully"<< std::endl;
		std::cout<<"your current value :: " << money << std::endl;
		}
	else 
	{
		std::cout<<"you cannot withdraw that amount of money, the value go below 0." << std::endl;
		std::cout<<"your current value :: " << money << std::endl; 
	}
}


std::string Account::toString() const{
return "account number :: " + std::to_string(unique) + " deposit money value :: " + std::to_string(money);
}