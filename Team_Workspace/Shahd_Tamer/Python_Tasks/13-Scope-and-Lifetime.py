#Scenario: You need to verify exactly when variables die in Python. Since if blocks don't kill variables, we must use a Function to create a limited scope.
class Tracker :
    # Constructor
    def __init__(self):
        print ("Tracker Born")
    # Destructor
    def __del__(self):
        print("Tracker Died")

# Main 
def test_scope():
    t1 = Tracker()
    print ("Inside Scope")

def main():
    test_scope()
    print(" END ")

if __name__== "__main__":
    main()