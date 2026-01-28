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

def update_light(light):
  match light.color:
    case LightColor.RED:
      light.color = LightColor.GREEN
      light.timer_seconds = 30
    case  LightColor.GREEN:  
      light.color = LightColor.YELLOW
      light.timer_seconds = 5
    case  LightColor.YELLOW:  
      light.color = LightColor.RED
      light.timer_seconds = 60


obj = TrafficLight(LightColor.RED , 60)
update_light(obj) 
print(obj.color)
update_light(obj) 
print(obj.color)
