#include "Bank_vector.hh"

Bank_vector::Bank_vector(int money){
	append(money);
	}

void Bank_vector::readnmakeAccounts(istream& in){
	int money;
	if(!(in>>money)){
		std::cerr<<"money value must be input"<<std::endl;
		std::exit(1);
	}
	append(money);
}

void Bank_vector::append(int money){
	Account* newAccount = new Account(money);
	bank_vector.push_back(newAccount);
}

Account* Bank_vector::findAccount(size_t acc){
	acc--;
	if(bank_vector[acc] != NULL) return bank_vector[acc];
	else{
		std::cerr<<"no account found"<<endl;
		std::exit(1);
	}
}

int Bank_vector::getBalance(size_t num){
	return findAccount(num)->getBalance();
}

void Bank_vector::deposit(size_t acc, int money){
	acc--;
	bank_vector[acc]->depositMoney(money);
}

bool Bank_vector::withdraw(size_t acc, int money){
	if(getBalance(acc) < money){
		return false;
	}
	acc--;
	bank_vector[acc]->withdrawMoney(money);
	return true;
}

void Bank_vector::deleteAccount(size_t key){
	key-=1;
	if(bank_vector[key] != NULL) bank_vector[key] = NULL;
	else{
		std::cerr<<"no account found"<<endl;
		std::exit(1);
	}
}

bool Bank_vector::transfer(size_t from, size_t to, int money){
	if(withdraw(from,money) == false) return false;
	else{
		deposit(to,money);
		return true;
	}
}


std::string Bank_vector::toString(){
	std::string ret ="[";
	for(int i = 0; i < bank_vector.size(); i++)
	{
		if(bank_vector[i] == NULL){
			ret+= "NULL, ";
		}
		else{
			ret+=bank_vector[i]->toString();
			ret+= ", ";
		}
	}
	ret+="]";
	return ret;
}

int main(){
	Bank_vector test(5);
	test.append(3);
	test.append(7);
	test.append(8);
	test.transfer(1,2,5);
	std::cout<<test.toString()<<std::endl;
}
