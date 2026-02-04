
class tracker:
    def __init__(self):
        print("Tracker Born")
    def __del__(self):
        print("Tracker Died")

print("Start")
def test_scope():
     t1=tracker()
     print("Inside Scope")
test_scope()
print("end of program")
#t1 died after func unlike if there is loop it wiil not die