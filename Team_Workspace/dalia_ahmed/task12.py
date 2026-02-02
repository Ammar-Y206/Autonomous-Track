
# import weakref

# robot = Robot()
# observer = weakref.ref(robot)

# del robot   , this delete robot and observer dont stop it
import sys
class  LidarData:
    def __init__(self):
        print("Data Allocated")
    def __del__(self):
        print("Data Freed")

main_ref=LidarData()
def process_data(data_ref):
    print ("Processing...")
    print(sys.getrefcount(data_ref))
process_data(main_ref)
main_ref=None
# print(sys.getrefcount(main_ref))