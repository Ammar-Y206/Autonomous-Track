class Tracker:
  def __init__(self):
    print("TrackerBorn")

  def __del__(self):  
    print("Tracker Died")

print("Start")
#def test_scope():
if True:
  t1 = Tracker()
  print("Inside Scope")

#test_scope()
print("End")