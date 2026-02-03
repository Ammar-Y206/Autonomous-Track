import sys

class LidarData:
    def __init__(self):
        print("Data Allocated")

    def __del__(self):
        print("Data Freed")
def process_data(data_ref):
    
    print("Processing...")
    print("Reference count inside function:", sys.getrefcount(data_ref))
# Create main reference
main_ref = LidarData()

print("Reference count before function:", sys.getrefcount(main_ref))

# Call function
process_data(main_ref)

print("Reference count after function:", sys.getrefcount(main_ref))

# Remove last reference
main_ref = None

print("End of program")
