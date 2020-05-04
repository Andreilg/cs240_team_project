#include "Bank_vector.hh"

Bank_vector::Bank_vector(int money){
	addAccount(money);
	}

void Bank_vector::readnmakeAccounts(istream& in){
	int money;
	if(!(in>>money)){
		std::cerr<<"money value must be input"<<std::endl;
		std::exit(1);
	}
	addAccount(money);
}

void Bank_vector::addAccount(int money){
	Account* newAccount = new Account(money);
	bank_vector.push_back(newAccount);
}

Account* Bank_vector::findAccount(size_t acc){
	acc-=1;
	if(bank_vector[acc] != NULL) return bank_vector[acc];
	else{
		std::cerr<<"no account found"<<endl;
		std::exit(1);
	}
}

void Bank_vector::deleteAccount(size_t key){
	key-=1;
	if(bank_vector[key] != NULL) bank_vector[key] = NULL;
	else{
		std::cerr<<"no account found"<<endl;
		std::exit(1);
	}
}
void Bank_vector::transfer(size_t from, size_t to, int money){
	from--;
	to--;
	if(bank_vector[from]!= NULL) bank_vector[from]->withdrawMoney(money);
	else{
		std::cerr<<"no account found"<<endl;
		std::exit(1);
	}

	if(bank_vector[from]!= NULL) bank_vector[to]->depositMoney(money);
	else{
		std::cerr<<"no account found"<<endl;
		std::exit(1);
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
	test.addAccount(3);
	test.addAccount(7);
	test.addAccount(8);
	test.transfer(1,2,3);
	std::cout<<test.toString()<<std::endl;
}
