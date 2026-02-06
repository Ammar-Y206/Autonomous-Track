# parent class
from mars_utils import Sensor
class Robots :
    def __init__(self,name,sensor_id):
        self.name = name 
        self.battery = 100  
        self .Sensor_id = sensor_id
        self.Sensor = Sensor(sensor_id)
        
        print(f"Robot {self.name} and its Sensor is  beeing created.")
    # distructor
    def __del__(self):
        del self.Sensor
        print(f"Robot {self.name} and its Sensor is being destroyed.")

    def move(self):
        print ("Robot moving Generic")

    def stop (self):
        self.speed = 0 
        print (f"Robot {self.name} has stopped")

    def  emergency_recharge(self):
        self.battery = 100

# chile class
class Rover(Robots):
    # to make initialization of parent work
    def __init__(self, name, sensor_id):
        super().__init__(name, sensor_id)
# Overriding to method move
    def move(self):
                    
                    self.battery -= 5
                    print(f"Rover {self.name} is Driving on Mars surface... Battery : {self.battery}%")
       

#another child class
class Drone(Robots):
       # to make initialization of parent work
    def __init__(self, name, sensor_id):
        super().__init__(name, sensor_id)
    # Overriding to method move
    def move (self):
                    self.battery -= 15 
                    print(f"Drone {self.name} is Flying  Mars surface... Battery : {self.battery}%")