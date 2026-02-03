# The inventory manager
#Scenario: You are managing the spare parts for the team. You need a system to count how many of each item you have.
# create config with data
inventory = {
    "Wheel": 4 ,
    "Motor": 2 , 
    "Sensor": 5
}
# A robot crashes and breaks a wheel
inventory ["Wheel"] -= 1 #should be 3 right now
# The team buys 3 new Motors
inventory["Motor"] += 3 # should be 5 right now
# to check what I did  above ' extra ' 
print (f"Wheel : {inventory[ "Wheel"]}")
print (f"Motor : {inventory[ "Motor"]}")
#print(inventory["Laser"]) # it crashes here and gives ' key error '
# safety way : return 0 if none like a default one
print (f" Laser {inventory.get("Laser", 0 )}")