class RobotID:
  def __init__(self):
    self.value = 1000
  
  def reset_ID(self, ref_to_id):  
    if ref_to_id is None:
      print("Error")
    else:
      ref_to_id.value = 0
      print("ID Reset")

my_ID = RobotID()
my_ID.reset_ID(my_ID)
print(my_ID.value)
my_ID.reset_ID(None)
