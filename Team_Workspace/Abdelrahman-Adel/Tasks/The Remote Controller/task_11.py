class RobotID:
    def __init__(self):
        self.value = 1000
def reset_id(ref_to_id):
    if ref_to_id is None:
        print("Error")
    else:
        ref_to_id.value = 0
        print("ID Reset")
# Create an instance my_id
my_id = RobotID()

# Call reset_id(my_id)
reset_id(my_id)

# Print value to confirm it changed
print(my_id.value)

# Bonus test
reset_id(None)
