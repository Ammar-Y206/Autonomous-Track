
class PaymentMethod:
    def pay(self, amount):
        print("Generic Payment")

class CreditCard(PaymentMethod):
    def pay(self, amount):
        print("Processing Credit Card: ",amount)

class Cash(PaymentMethod):
    def pay(self, amount):
        print("Accepting Cash: ",amount)



method=CreditCard()
method.pay(15.0)
method=Cash()
method.pay(15.0)
