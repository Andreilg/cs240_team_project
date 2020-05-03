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
	for(unsigned int i = 0; i<bank_vector.size();i++){
		if(acc == bank_vector[i]->getAccountNum()) return bank_vector[i];
		else{
			std::cerr<<"no accound founded"<<endl;
			std::exit(1);
		}
	}
}

void Bank_vector::deleteAccount(size_t key){
	for(unsigned int i = 0; i<bank_vector.size();i++){
		if(key == bank_vector[i]->getAccountNum()) bank_vector[i] == NULL;
		else{
			std::cerr<<"no accound founded"<<endl;
			std::exit(1);
		}
	}
}
void Bank_vector::transfer(size_t from, size_t to, int money){
	for(unsigned int i = 0; i<bank_vector.size();i++){
			if(from == bank_vector[i]->getAccountNum()) bank_vector[i]->withdrawMoney(money);
			else{
				std::cerr<<"no accound founded"<<endl;
				std::exit(1);
			}
		}
	for(unsigned int i = 0; i<bank_vector.size();i++){
		if(to == bank_vector[i]->getAccountNum()) bank_vector[i]->depositMoney(money);
		else{
			std::cerr<<"no accound founded"<<endl;
			std::exit(1);
		}
	}
}

