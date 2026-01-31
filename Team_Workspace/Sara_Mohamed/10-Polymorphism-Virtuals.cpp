#include <iostream>
using namespace std;

class PaymentMethod{
public :
    virtual void pay(double amount){
        cout << "Generic Payment processing..." << endl;
    }
};

class CreditCard : public PaymentMethod {
public :
    void pay( double amount ) override{
        cout << "Processing Credit Card payment of "<< amount <<endl;
    } 
};

class Cash : public PaymentMethod {
public :
    void pay( double amount ) override{
        cout <<"Accepting Cash payment of" << amount <<endl;
    } 
};

int main()
{
    CreditCard myCard;
    PaymentMethod& paymentSystem = myCard;
    paymentSystem.pay(15.50);

    return 0;
}
