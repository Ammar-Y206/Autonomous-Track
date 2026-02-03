class PaymentMethod:
    def pay(self, amount):
        print(f"Generic Payment {amount}")
class CreditCard(PaymentMethod) :
    def pay(self, amount) :
        print(f"Processing Credit Card: {amount}")
class Cash(PaymentMethod) :
    def pay(self, amount) :
        print(f"Accepting Cash: {amount}")
method = CreditCard()
method.pay(15.0)
method = Cash()
method.pay(5.0)