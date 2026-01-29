// task7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Account {
private:
    double balance = 0.0;
public:
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "invalid amount.." << endl;

    }
    double withdraw(double amount) {
        if (amount <= balance)
        {
            balance -= amount;
           // cout << "amount is : " << amount << endl;
            return amount;
        }
        else {
            cout << "Insufficient funds";
            return 0;
        }
    }
    double getBalance() {
        return balance;

    }

};
int main()
{
    Account user1;
   // user1.balance = 1000000;

    user1.deposit(100);
    user1.withdraw(50);

    cout << "user balance is:" << user1.getBalance() << endl;
}

