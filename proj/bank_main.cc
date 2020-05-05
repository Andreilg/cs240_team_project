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
    if (file.is_open())
    {
        string tp;
        while (getline(file, tp))
        {
            int money = stoi(tp);
            //start = clock();
            testLink.append(money);
            testVector.append(money);
            //end = clock();
            //appendTime += 1000*((double) (end-start))/(CLOCKS_PER_SEC);
            //cout<< money << "\n";
        }
        file.close();
    }

    clock_t start, end;
    // *** Linked List ***
    int n = testLink.getSize();
    //recording append time
    start = clock();
    testLink.append(100);//append is always O(1)
    end = clock();
    double appendTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording find time
    start = clock();
    testLink.find_Account((n + 1) / 2); //findTime is O(n)
    end = clock();
    double findTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording transfer time
    start = clock();
    testLink.transfer((n + 1) / 2, ((n + 1) / 2) + 1, 1); //transferTime is O(n)
    end = clock();
    double transferTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording getBalance time
    start = clock();
    testLink.getBalance((n + 1) / 2); //balanceTime is O(n)
    end = clock();
    double balanceTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording deposit time
    start = clock();
    testLink.deposit((n + 1) / 2, 1); //depositTime is O(n)
    end = clock();
    double depositTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording withdraw time
    start = clock();
    testLink.withdraw((n + 1) / 2, 1); //withdrawTime is O(n)
    end = clock();
    double withdrawTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording delete time
    start = clock();
    testLink.deleteAccount((n + 1) / 2);//delete varies but average case is O(n)
    end = clock();
    double deleteTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //printing time outputs
    cout << "Linked List: Milliseconds elapsed for appending an extra element to " << n
         << " elements: " << appendTime << endl;
    cout << "Linked List: Milliseconds elapsed for finding an element at " << n
         << "/2 index: " << findTime << endl;
    cout << "Linked List: Milliseconds elapsed for transferring money from " << n
         << "/2 index to " << n << "/2 + 1 index: " << transferTime << endl;
    cout << "Linked List: Milliseconds elapsed for getting balance at " << n
         << "/2 index: " << balanceTime << endl;
    cout << "Linked List: Milliseconds elapsed for depositing money at " << n
         << "/2 index: " << depositTime << endl;
    cout << "Linked List: Milliseconds elapsed for withdrawing money at " << n
         << "/2 index: " << withdrawTime << endl;
    cout << "Linked List: Milliseconds elapsed for deleting an element at " << n
         << "/2 index: " << deleteTime << endl;

    // *** Linked List ***
    //n = testVector.getSize();
    //recording append time
    start = clock();
    testVector.append(100);//append is always O(1)
    end = clock();
    appendTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording find time
    start = clock();
    testVector.find_Account((n + 1) / 2); //findTime is O(n)
    end = clock();
    findTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording transfer time
    start = clock();
    testVector.transfer((n + 1) / 2, ((n + 1) / 2) + 1, 1); //transferTime is O(n)
    end = clock();
    transferTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording getBalance time
    start = clock();
    testVector.getBalance((n + 1) / 2); //balanceTime is O(n)
    end = clock();
    balanceTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording deposit time
    start = clock();
    testVector.deposit((n + 1) / 2, 1); //depositTime is O(n)
    end = clock();
    depositTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording withdraw time
    start = clock();
    testVector.withdraw((n + 1) / 2, 1); //withdrawTime is O(n)
    end = clock();
    withdrawTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //recording delete time
    start = clock();
    testVector.deleteAccount((n + 1) / 2);//delete varies but average case is O(n)
    end = clock();
    deleteTime = 1000 * ((double) (end - start)) / (CLOCKS_PER_SEC);
    //printing time outputs
    cout << "Vector: Milliseconds elapsed for appending an extra element to " << n
         << " elements: " << appendTime << endl;
    cout << "Vector: Milliseconds elapsed for finding an element at " << n
         << "/2 index: " << findTime << endl;
    cout << "Vector: Milliseconds elapsed for transferring money from " << n
         << "/2 index to " << n << "/2 + 1 index: " << transferTime << endl;
    cout << "Vector: Milliseconds elapsed for getting balance at " << n
         << "/2 index: " << balanceTime << endl;
    cout << "Vector: Milliseconds elapsed for depositing money at " << n
         << "/2 index: " << depositTime << endl;
    cout << "Vector: Milliseconds elapsed for withdrawing money at " << n
         << "/2 index: " << withdrawTime << endl;
    cout << "Vector: Milliseconds elapsed for deleting an element at " << n
         << "/2 index: " << deleteTime << endl;
}
