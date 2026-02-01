#he Payment Gateway
# You are building a vending machine that accepts different payment methods
# Base Class:
class  PaymentMethod :
    def pay(self, amount) :
        #Default behavior
        print ("Generic Payment")
# Derived Class
class CreditCard (PaymentMethod):
    # over riding
    def pay (self, amount):
         print (f"Processing Credit Card: $ {amount}")
# Derived Class
class Cash(PaymentMethod):
    def pay (self, amount):
        print (f"Accepting Cash: ${amount}")

# Main Execution
# Create a variable method and assign it a CreditCard object
my_payment = CreditCard()
my_payment.pay(15.0)

#Switch it: Now assign method a Cash object.
my_payment = Cash()
my_payment.pay(5.0)