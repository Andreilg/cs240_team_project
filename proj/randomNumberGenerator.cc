#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
  //int test = rand();
  if(argc == 1 || argc > 2){
    cout<< "USE: ./generate <# of ints>" <<endl;
    return 0;
  }
  int numberElements = stoi(argv[1]);
  fstream file;
  file.open("test.txt", ios::out);
  if(!file){
    cout<<"File creation error"<<endl;
    return 0;
  }
  for(int i = 0; i< numberElements; i++){
    file << rand() << '\n';
  }
  //std::cout<<test<<std::endl;
  file.close();
  return 0;
}
