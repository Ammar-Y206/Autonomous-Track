
class logger:
    def __init__(self):
      print("--- LOG STARTED ---")
    def __del__(self):
       print("--- LOG SAVED & CLOSED ---")

print ("step1")

def test_scope():
   mylogger=logger()
   print ("Step 2 (Inside Function)")
test_scope()
print ("Step 3 (Outside Function)")
