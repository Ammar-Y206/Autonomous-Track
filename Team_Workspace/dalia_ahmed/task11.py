
class RobotId:
    def __init__(self):
     self.value=100
def reset_id(ref_to_id):
       if ref_to_id is None:
          print("error")
       else:
          ref_to_id.value = 0
          print("id reset")
        


my_id=RobotId()
reset_id(my_id)
print(my_id.value)
reset_id(None)
# we used object instead of int to modify it
# this clarifies that my_id is by ref because the value changed 
          
       
