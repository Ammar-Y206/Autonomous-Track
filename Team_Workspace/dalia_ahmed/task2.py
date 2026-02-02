
gear ="D"
speed=0.0
def set_speedby_gear(gear):
    match gear:
        case "p":
            speed=0
            print("Parking")
        case "D":
            speed=10
            print("Driving Forward")
        case "R":
            speed=-5
            print("Reversing")
        case _:
            speed=0
            print("Error: Unknown Gear")
set_speedby_gear(gear)
        
          

