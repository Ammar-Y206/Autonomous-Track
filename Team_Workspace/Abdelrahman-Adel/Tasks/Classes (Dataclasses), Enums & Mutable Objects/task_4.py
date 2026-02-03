from enum import Enum
from dataclasses import dataclass

class LightColor(Enum):
    RED = 1
    YELLOW = 2
    GREEN = 3


@dataclass
class TrafficLight:
    color: LightColor
    timer_seconds: int


def update_light(light: TrafficLight):
    if light.color == LightColor.RED:
        light.color = LightColor.GREEN
        light.timer_seconds = 30
    elif light.color == LightColor.GREEN:
        light.color = LightColor.YELLOW
        light.timer_seconds = 5
    elif light.color == LightColor.YELLOW:
        light.color = LightColor.RED
        light.timer_seconds = 60

traffic_light = TrafficLight(color=LightColor.RED, timer_seconds=60)

update_light(traffic_light)  
update_light(traffic_light)  

print(f"Final State: {traffic_light.color.name}, Timer: {traffic_light.timer_seconds}s")
