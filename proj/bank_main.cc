#include<iostream>
#include<istream>
#include<string>
#include<fstream>
#include "Account.hh"
#include "Account_node.hh"
#include "Bank_vector.hh"
#include "Bank_linked.hh"

using namespace std;

//int main(int argc, char* argv[]){
int main(){
  Bank_linked xd = new Bank_linked();
  fstream file;
  file.open("./test.txt",ios::out);
  return 0;
}
