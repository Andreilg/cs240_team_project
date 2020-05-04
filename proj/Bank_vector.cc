#include "Bank_vector.h"

Bank_vector::Bank_vector(int money){
	account = new Account(money);
	}
	
void Bank_vector::readnmakeAccounts(istream& in){
	int money;
	if(!(in>>money)){
		std::cerr<<"money value must be input"<<std::endl;
		std::exit(1);
	}
	addAccount(money);
}

Account* Bank_vector::getAccount(){
	return this->account;
}
	
void Bank_vector::addAccount(int money){
	Account* newAccount = new Account(money);
	bank_vector.push_back(newAccount);
}

Account* Bank_vector::findAccount(size_t acc){
	if(bank_vector[acc] != NULL) return bank_vector[acc];
	else{
		std::cerr<<"no accound founded"<<endl;
		std::exit(1);
	}
}

void Bank_vector::deleteAccount(size_t key){
	if(bank_vector[key] != NULL) bank_vector[key] == NULL;
	else{
		std::cerr<<"no accound founded"<<endl;
		std::exit(1);
	}
}
void Bank_vector::transfer(size_t from, size_t to, int money){
	if(bank_vector[from]!= NULL) bank_vector[from]->withdrawMoney(money);
	else{
		std::cerr<<"no accound founded"<<endl;
		std::exit(1);
	}
	
	if(bank_vector[from]!= NULL) bank_vector[to]->depositMoney(money);
	else{
		std::cerr<<"no accound founded"<<endl;
		std::exit(1);
	}
	
}
