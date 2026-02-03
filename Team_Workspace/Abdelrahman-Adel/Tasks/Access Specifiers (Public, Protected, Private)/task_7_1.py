class Account :
    def __init__(self):
        self.__balance = 0.0
    def deposit(self, amount):
        if amount> 0:
            self.__balance += amount
        else:
            print("Invalid amount")
    def withdraw(self, amount):
        if amount <= self.__balance :
            amount -= self.__balance
            return amount
        else:
            print("Insufficient funds")
            return 0
my_account = Account()
my_account.__balance = 1000000
my_account.deposit(100)
my_account.withdraw(50)
        