# The Secure Session
# Scenario: You are writing a Logger system. When a logging session starts, it must print "Log Started". When it ends, it must print "Log Saved & Closed" to ensure data isn't lost.
#1 
class Logger :
    # 2 --- CONSTRUCTOR ---
    def __init__(self):
        print ("--- LOG STARTED ---")
    # 3 --- DESTRUCTOR ---
    # Runs when the object is deleted (garbage collected)
    def __del__(self):
        print("--- LOG SAVED & CLOSED ---")
#Main Execution 
# 1 
print ("Step 1")
# 2 
def test_scope():
# 3 creation a logger object
    new_logger = Logger ()
    print("Step 2 (Inside Function)")
# 4 call func 
test_scope()
#5 
print ("Step 3 (Outside Function)")