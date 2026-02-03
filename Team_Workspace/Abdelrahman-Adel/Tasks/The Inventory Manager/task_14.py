inventory = {
    "Wheel": 4,
    "Motor": 2,
    "Sensor": 5
}
# Robot crashes → breaks one wheel
inventory["Wheel"] -= 1

# Team buys 3 new motors
inventory["Motor"] += 3
# print(inventory["Laser"])
print(inventory.get("Laser", 0))

