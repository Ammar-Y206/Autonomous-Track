#include <iostream>

using namespace std;

class Account {
    private:
        double balance;

    public:
        Account() {
           balance = 0.0;
        }

        void deposit(double amount) {
            if (amount > 0.0) {    
                balance = balance + amount; 
            } else {
                cout << "Invalid amount" << endl;
            }
        }

        double withdraw(double amount) {
            if (amount <= balance) {    
                balance = balance - amount;
                return amount;
            } else {
                cout << "Insufficient funds" << endl;
                return 0;
            }
        }
        
        double getBalance() {
            return balance;
        }
};

int main() {
    Account my_account;
    
    my_account.deposit(100.0);
    my_account.withdraw(50.0);
    
    cout << "Final Balance: " << my_account.getBalance() << endl;

    return 0;
}