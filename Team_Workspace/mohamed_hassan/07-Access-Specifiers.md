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
            cout << "Invalid amount" << endl;
    }

    double withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return amount;
        } else {
            cout << "Insufficient funds" << endl;
            return 0;
        }
    }
};

int main() {
    Account my_account;

    

    my_account.deposit(100);
    my_account.withdraw(50);

    return 0;
}
