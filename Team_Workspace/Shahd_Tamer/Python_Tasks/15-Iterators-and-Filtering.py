# The Clean-Up Crew
# Scenario: You have a list of sensor readings. Some are valid (positive), but some are errors (negative). You need to clean the list.
readings = [10, -5, 20, -1, 30]

#  List Comprehension to clan up list above
valid_readings = [val for val in readings if val >= 0 ] # this should be [10,20,30]

# OUTPUT
print(f"Valid Readings : {valid_readings}")