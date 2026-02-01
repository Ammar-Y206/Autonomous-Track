# The Vehicle Factory
# Scenario: You are building a simulation with different types of vehicles.
#Create a Parent Class
class Vehicle :
    # Constructor
    def __init__ (self):
        self._speed  = 0.0
#Public Method: sets speed 
    def set_speed(self, s):
        if s >=0 :
            self._speed= s 
            #print(f"Speed set to {s}")   # extra
        else :
            print("Error speed must be positive")
            return 0.0
# puplic method :  shows speed
    def show_speed (self):
        print(f"Current Speed is {self._speed}")
# create child class
class SportsCar(Vehicle):
    def turbo_boost(self) :
        self._speed = self._speed * 2 
        print(" TURBO ACTIVATED! ")

# Main Execution 
my_vehicle = SportsCar()
my_vehicle .set_speed(50)
my_vehicle.turbo_boost()
my_vehicle.show_speed()