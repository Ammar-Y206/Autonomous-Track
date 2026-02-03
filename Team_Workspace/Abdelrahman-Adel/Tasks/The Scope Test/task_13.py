class Tracker:
    def __init__(self):
        print("Tracker Born")

    def __del__(self):
        print("Tracker Died")
print("Start")

def test_scope():
    t1 = Tracker()
    print("Inside Scope")

test_scope()

print("End")
