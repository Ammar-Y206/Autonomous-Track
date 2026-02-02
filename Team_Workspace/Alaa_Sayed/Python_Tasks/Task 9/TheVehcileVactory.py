class Vehicle:
  def __init__(self):
    self._speed = 0.0

  def set_speed(self, s):
    self._speed = s

  def show_speed(self):
    print(f"Current Speed: {self._speed}") 

class SportsCar(Vehicle):
  def turbo_boost(self):
    new_speed = super()_speed * 2      
    print(f"new speed is {new_speed} ") 
    print("TURBO ACTIVATED!")  

s = SportsCar()
s.set_speed(50) 
s.turbo_boost()
s.show_speed()  