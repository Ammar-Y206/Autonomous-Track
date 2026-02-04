from robots import Rover
from robots import Drone
def EXECUTE_MISSION(fleet):
    print("\n--- EXECUTING MISSION ---")
    for bot in fleet:
        bot.move()


# Create mixed fleet
fleet = [
    Rover("Curiosity", 3.14),
    Drone("Ingenuity", "Wind Data"),
    Rover("Perseverance", 42)
]

# Run mission cycles
for _ in range(6):
    EXECUTE_MISSION(fleet)

# Prove garbage collection
print("\n--- Deleting Perseverance ---\n")
del fleet[2]