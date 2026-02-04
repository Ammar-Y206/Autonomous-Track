from robots import Rover
from robots import Drone

r1= Rover(100)
r2 = Rover(15)
d1 = Drone(70)

list = [r1 , r2 , d1]

for x in list:
  x.Execute_Mission()


