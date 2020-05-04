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
  Bank_linked test();
  fstream file;
  file.open("./test.txt",ios::out);
  if(file.is_open()){
    string tp;
    while(getline(file,tp)){
      cout<< tp << "\n";
    }
  }
  file.close();
  return 0;
}
