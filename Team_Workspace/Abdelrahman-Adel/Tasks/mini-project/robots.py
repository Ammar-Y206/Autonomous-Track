from mars_utils import Sensor
class Robot:
    def __init__(self, name: str, sensor_data):
        self.name = name
        self.battery = 100
        self.sensor = Sensor(sensor_id=id(self), data=sensor_data)

    def emergency_recharge(self):
        print(f"{self.name}: EMERGENCY RECHARGE ACTIVATED")
        self.battery = 100

    def move(self):
        pass  # To be overridden

    def __del__(self):
        print(f"Robot {self.name} Destroyed")


class Rover(Robot):
    def move(self):
        if self.battery <= 20:
            print(f"{self.name}: Battery critical. Movement forbidden.")
            self.emergency_recharge()
            return

        self.battery -= 5
        print(f"{self.name} is driving | Battery: {self.battery}%")


class Drone(Robot):
    def move(self):
        if self.battery <= 20:
            print(f"{self.name}: Battery critical. Flight forbidden.")
            self.emergency_recharge()
            return

        self.battery -= 15
        print(f"{self.name} is flying | Battery: {self.battery}%")
