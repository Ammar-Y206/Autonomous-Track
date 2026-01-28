from enum import Enum
from dataclasses import dataclass

#Define the light color
class LightColor(Enum):
    RED = 0
    YELLOW = 1
    GREEN =2 

#define the dataclass
@dataclass
class TrafficLight :
    color : LightColor
    timer_seconds : int 

#function update opject
def update_light (light):
    if light.color == LightColor.RED :
        light.color = LightColor.GREEN
        light.timer_seconds = 30

    elif light.color == LightColor.GREEN :
        light.color =LightColor.YELLOW
        light.timer_seconds = 5

    else :
        light.color = LightColor.RED
        light.timer_seconds = 60 

# Main Execution 
# Initialize Dataclass
my_light = TrafficLight (color= LightColor.RED , timer_seconds= 60)

#CALLING UPDATE FUNCTION 
update_light(my_light)
print(f"The state is '{my_light.color.name}' ")
#Calling it twice to check elif condition
update_light(my_light)
print(f"The  state is' {my_light.color.name}'")  ## required in task
# calling it triple to check last condition
update_light(my_light)
print(f"The  final state is ' {my_light.color.name}'")