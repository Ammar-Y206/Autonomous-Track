class Vehicle :
    def __init__(self):
        self._speed = 0.0
    def set_speed(self, s):
        self._speed = s
    def show_speed(self):
        print("Current Speed :" +str(self._speed))
class SportsCar(Vehicle):
    def turbo_boost(self):
        self._speed *= 2
        print("TURBO ACTIVATED!")
BMW = SportsCar()
BMW.set_speed(50)
BMW.turbo_boost()
BMW.show_speed()