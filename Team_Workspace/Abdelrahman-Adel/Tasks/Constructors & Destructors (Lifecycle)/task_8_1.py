class Logger :
    def __init__(self):
        print("--- LOG STARTED ---")
    def __del__(self):
        print("--- LOG SAVED & CLOSED ---")
print("Step 1")
def test_scope(): 
    log = Logger()
    print("Step 2 (Inside Function)")
test_scope()
print("Step 3 (Outside Function)")