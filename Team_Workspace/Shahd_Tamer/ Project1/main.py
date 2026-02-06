from robots import Rover
from robots import Drone 

# creating objects 
Rover1 = Rover ("Alpha ",1234)
Rover2 =Rover ("Beta",52745)
Drone1 = Drone("flyingD1",45678)

fleet = [Rover1 , Rover2 , Drone1]

print (" Mission Started")
Rover1.battery = 10
Rover2.battery= 75
print("="*30 + "\n")


for bot in fleet:
        if bot.battery <= 20 :
                print (f" Warning Battery of {bot.name} is Low needs recharging ")
                bot.stop()
                bot.emergency_recharge()
                print(f"{bot.name} is full charged")
        else :
                bot.move()
        print("-" * 20)
           
       

del fleet
print("\n" + "="*30)
print ("missin ended")
print("="*30)