#include<iostream>
#include<istream>
#include<string>
#include<fstream>
#include "Account.hh"
#include "Account_node.hh"
#include "Bank_vector.hh"
#include "Bank_linked.hh"
#include <ctime>

using namespace std;

//int main(int argc, char* argv[]){
int main()
{
    Bank_linked testLink;
    Bank_vector testVector;
    ifstream file("test.txt");
    clock_t start, end;
    if (file.is_open())
    {
        string tp;
        while (getline(file, tp))
        {
            int money = stoi(tp);
            //start = clock();
            testLink.append(money);
            //end = clock();
            //appendTime += 1000*((double) (end-start))/(CLOCKS_PER_SEC);
            //cout<< money << "\n";
        }
        file.close();
    }
    int originalSize = testLink.getSize();
    //recording append time
    start = clock();
    testLink.append(100);//append is always O(1)
    end = clock();
    double appendTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording find time
    start = clock();
    testLink.find_Account(originalSize / 2); //findTime is O(n)
    end = clock();
    double findTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording transfer time
    start = clock();
    testLink.transfer(originalSize / 2, originalSize / 2 + 1, 1); //transferTime is O(n)
    end = clock();
    double transferTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording getBalance time
    start = clock();
    testLink.getBalance(originalSize / 2); //balanceTime is O(n)
    end = clock();
    double balanceTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording deposit time
    start = clock();
    testLink.deposit(originalSize / 2, 1); //depositTime is O(n)
    end = clock();
    double depositTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording withdraw time
    start = clock();
    testLink.withdraw(originalSize / 2, 1); //withdrawTime is O(n)
    end = clock();
    double withdrawTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording delete time
    start = clock();
    testLink.deleteAccount(originalSize / 2);//delete varies but average case is O(n)
    end = clock();
    double deleteTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //printing time outputs
    cout << "Linked List: Milliseconds elapsed for appending an extra element to " << originalSize
         << " elements: " << appendTime << endl;
    cout << "Linked List: Milliseconds elapsed for finding an element at " << originalSize
         << "/2 index: " << findTime << endl;
    cout << "Linked List: Milliseconds elapsed for transferring money from " << originalSize
         << "/2 index to " << originalSize << "/2 + 1 index: " << transferTime << endl;
    cout << "Linked List: Milliseconds elapsed for getting balance at " << originalSize
         << "/2 index: " << balanceTime << endl;
    cout << "Linked List: Milliseconds elapsed for depositing money at " << originalSize
         << "/2 index: " << depositTime << endl;
    cout << "Linked List: Milliseconds elapsed for withdrawing money at " << originalSize
         << "/2 index: " << withdrawTime << endl;
    cout << "Linked List: Milliseconds elapsed for deleting an element at " << originalSize
         << "/2 index: " << deleteTime << endl;


}
