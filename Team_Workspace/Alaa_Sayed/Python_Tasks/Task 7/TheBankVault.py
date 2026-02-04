class Account:
  
  def __init__(self):
    self.__balance = 0.0
  
  def deposit(self, amount):
    if amount > 0:
      self.__balance += amount
    else: 
      print("Invalid amount")

  def withdraw(self, amount):
    if amount <= self.__balance:
      self.__balance -= amount
      return amount
    else:
      print("Insufficient Funds")
      return 0
    
a = Account()

a.deposit(100)
a.withdraw(50)
print(f"Your Account Balance is: {a._Account__balance}")


