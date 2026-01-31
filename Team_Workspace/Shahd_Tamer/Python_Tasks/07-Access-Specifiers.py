#Scenario: You are creating a class for a Bank Account (or a Robot's Power Budget).
# 1 creating class
class Account :
    def __init__(self):
        # DATA IS PRIVATE (Double Underscore)
        # 2 No one outside can mess with this variable easily.
        self.__balance = 0.0 

        # 3 Public Method
        # purpose :charging battery
    def deposit(self, amount):
            if amount >0 :
                self.__balance +=  amount 
                print ("Added to balance")
            else :
                print ("invalid amount ")

    #Public Method
    #  purpose : consume energy
    def withdraw(self, amount):
         if amount <= self.__balance :
              self.__balance -= amount
              return amount
         ## energy is -ve " checking "
         else :
               print ("Insufficient funds")
               return 0 
    ## added not from req 
    # to cheack balance in main using getter
    def get_balance(self):
               return self.__balance
# Main Execution 
# Creating  an object using the class
my_account = Account()
my_account.__balance = 1000000  #trying to cheat   
my_account.withdraw(50)  #check if the million dollars is actually there. (Spoiler: It won't be)
my_account.deposit(100)
my_account.withdraw(50)
# for checking what happened
print (f" The  Actual Balance is {my_account.get_balance()}")