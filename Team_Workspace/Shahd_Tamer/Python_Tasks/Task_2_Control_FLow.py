#The "Robot Gearbox" 
#"P" for Park, "D" for Drive, "R" for Reverse
gear = "D"
speed = 0.0
# --- Part 1: Match (State Management) ---
match gear:
    case "P":
       speed = 0
       print (" Parking.")

    case "D":
        speed = 10 
        print("Driving  Forward. ")
        
    case "R":
        speed = -5
        print("Reversing .")

    case _:
        speed = 0 
        print("ERROR: Unknown geer.")

print (f"speed is : {speed}")