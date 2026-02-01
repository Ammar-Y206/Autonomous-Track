# The Remote Controller
#Scenario: You have a robot with a specific ID. You want a function that can reset this ID.
#Challenge: Because Integers are immutable in Python, passing just the number id to a function won't work (it would create a copy). To simulate "Pointer behavior" with data, we must wrap the data in a Class or a List.
class RobotID :
    def __init__ (self):
        self.value = 1000
def reset_id(ref_to_id):
    if ref_to_id is None :
        print (" Error ")
    else :
        ref_to_id.value = 0 
        print ( "ID Reset")

if __name__ == "__main__":
    my_id = RobotID()
    reset_id (my_id) # هنا انا باعته فيخش جوا "else"  وينفذ "object"   فبأكد ان في روبوت حقيقي
    print (f" My ID value is {my_id.value}")
    #Bonus
    reset_id(None) # هنا مش باعتله حاجه فاضي  فهيرجع ايرور