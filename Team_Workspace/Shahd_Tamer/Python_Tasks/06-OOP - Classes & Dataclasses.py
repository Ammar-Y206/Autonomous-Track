#Scenario: You are building a thermostat for a robot's CPU. You want to ensure the target temperature is never set to a dangerous level.
from dataclasses import dataclass
class Thermostat :
    def __init__(self): 
         # We use an underscore '__' to signal this is Private/Internal and make it hard to edit on it out of class 
        self.__target_temp = 0.0 

    # puplic method to modify temp 
    def set_temperature(self, temp):
        if temp > 100 :    # logic safety
            print("WARNING: Too Hot!")
            self.__target_temp = 100.0 
        else :
            self.__target_temp = temp

    # Method to read state safely
    def get_temperature(self):
        return self.__target_temp
    
# Main Excution
# Creating  an object using the class
cpu_monitor = Thermostat()
cpu_monitor.set_temperature(150)

#print actual temp using getter method
print (f"The actual temp is {cpu_monitor.get_temperature()} ")
## added not req in task "below"
# cpu_monitor.set_temperature(50)
# print (f"The actual temp is {cpu_monitor.get_temperature()} ")