class Robot:
  def __init__(self , battery):
    self.battery = battery
    print("Robot's sensors have been activated")

  def __del__(self):
    print("Sensor [ID] Destroyed")  

  def Execute_Mission(self):
    pass 




class Rover(Robot):
  
  def __init__(self, battery):
    super().__init__(battery)
    self.battery = battery
    print("Rovers must DRIVE")

  def stop(self):
    self.speed =0
    print("Rover STOPPED")  

  def emergency_recharge(self):
    self.battery = 100

  def Execute_Mission(self):
    if self.battery <=20:
      self.stop()
      self.emergency_recharge()
    else:  
      self.battery -= 5
      print("Battery level changed")



class Drone(Robot):

  def __init__(self, battery):
    self.battery = battery
    super().__init__(battery)
    print("Drones must FLY")

  def stop(self):
    self.speed = 0
    print("Drone STOPPED")  

  def emergency_recharge(self):
    self.battery = 100

  def Execute_Mission(self):
    if self.battery <=20:
      self.stop()
      self.emergency_recharge()
    else:
      self.battery -= 15
      print("Battery level changed")

