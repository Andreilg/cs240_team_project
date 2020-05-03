#include<iostream>
#include<string>
#include<istream>
#include<cstdlib>

#include"Bank_linked.h"

using namespace std;

//int main(int argc, char* argv[]){
int main(){
	Account * account1 = new Account(0000000001);
	Account * account2 = new Account(0000000002,300);
	cout<<account1->toString()<<endl;
	cout<<account2->toString()<<endl;
	/*
	if(argc != 2){
		cout<<endl;
		cerr << " usage:: " << argv[0] << " user info" << endl;
    	exit(1);
	}
	*/
	return 0;
}
