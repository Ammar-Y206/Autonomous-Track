from typing import TypeVar, Generic
T = TypeVar('T')

class Sensor(Generic[T]):
    def __init__(self, sensor_id: int, data: T):
        self.sensor_id = sensor_id
        self.data = data

    def __del__(self):
        print(f"Sensor {self.sensor_id} Destroyed")

