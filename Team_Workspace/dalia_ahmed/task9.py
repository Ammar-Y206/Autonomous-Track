
#parent
class Vehicle:
    def __init__(self):
        self._speed=0.0
    def set_speed(self, s):
        self._speed=s
    def show_speed(self):
        print("current speed:",self._speed)


class SportsCar(Vehicle):
    def turbo_boost(self):
        self._speed*=2
        print("TURBO ACTIVATED!")




my_car=SportsCar()
my_car.set_speed(50)
my_car.turbo_boost()
my_car.show_speed()
