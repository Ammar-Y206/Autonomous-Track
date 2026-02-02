# The Shared Sensor
# Scenario: You have a Lidar data object. Two different variables need to hold it, and we want to verify when it gets deleted from memory.
import sys
class LidarData :
    #Constructor 
    def __init__(self):
        print ("Data Allocated")
    
    # Distructor
    def __del__(self):
        print ("Data Freed")
def process_data(data_ref):
         print ("Processing...")
         print(f"Ref Count: {sys.getrefcount(data_ref) - 1} ")
         
# Main
def main() :
     main_ref = LidarData()
     process_data(main_ref)
     main_ref = None # refcound  must be reached to 0 

    
if __name__ == "__main__":
    main()