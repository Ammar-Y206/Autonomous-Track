#include <iostream>
using namespace std;

class Account {
private:
    double balance = 0.0;  // Private and protected

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Invalid amount" << endl;
        }
    }

    double withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return amount;
        } else {
            cout << "Insufficient funds" << endl;
            return 0.0;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    Account my_account;

    // (this will NOT compile)
    // my_account.balance = 1000000;  // ERROR: balance is private

    // Legal interaction
    my_account.deposit(100);
    my_account.withdraw(50);

    cout << "Final balance: "
         << my_account.getBalance() << endl;

    return 0;
}
