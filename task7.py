
class account:
    def __init__(self):
        self.__balance=0.0
    def deposit(self, amount):
        if amount>0:
            self.__balance += amount
            return self.__balance
        else:
            print("Invalid amount")
    def withdraw(self, amount):
        if amount<=self.__balance:
            self.__balance -= amount
            return self.__balance
        else:
            print("Insufficient funds")
            return 0
        
myaccount=account()
        
# myaccount.__balance = 1000000 dont work 
print(myaccount.withdraw(50))
print(myaccount.deposit(100))


