
from enum import Enum
from dataclasses import dataclass
class light_colors(Enum):
    RED=0
    YELLOW=1
    GREEN=2
@dataclass
class TraficLight:
    color: light_colors
    timer_seconds: int
def update_light(light):
    match light.color:
        case light_colors.RED:
            light.color=light_colors.GREEN
            light.timer_seconds=30
            print(light)
        case light_colors.GREEN:
            light.color=light_colors.YELLOW
            light.timer_seconds=5
            print(light)
        case light_colors.YELLOW:
            light.color=light_colors.RED
            light.timer_seconds=60
            print(light)

mytrafic=TraficLight(light_colors.RED,60)
update_light(mytrafic)
update_light(mytrafic)

            
