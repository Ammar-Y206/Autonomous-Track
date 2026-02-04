from mars_utils import sensor
class robot:
     def __init__(self,name,sensor_id):
          self.sensor=sensor(sensor_id)
          self.sensor.id=sensor_id
          self.name=name
          self.battery=100
          self.is_moving=False
    
# it is making Exception, so we use try method later
#from
     def __del__(self):
          print ("Sensor ",self.sensor.id, " Destroyed" )
          del self.sensor
#end
     def execute_mission(self):
          print("robot ",self.name," is operating")
     def move(self):
          print(" i am the robot")
     def stop(self):
          self.is_moving=False
          print(self.name," has stopped right now")
     def recharge(self):
          print(self.name," is charging.....")
          self.battery=100
          print(self.name," is full charging.")
          
     
          
###############
class rover(robot):
    def execute_mission(self):
         self.move()
         self.battery-=5
         print(f"{self.name} driving. Battery: {self.battery}%")

          
    def move(self):
          print(self.name," is driving")
          
##############
class drone(robot):
     def execute_mission(self):
          self.move()
          self.battery-=10
          print(f"{self.name} flying. Battery: {self.battery}%")

     def move(self):
          print(self.name," is flying")