import sys
class LidarData:

  def __init__(self):
    print("Data Allocated")

  def __del__(self):
    print("Data Freed")

main_ref = LidarData()
data_ref = main_ref

def process_data(data_ref):
  print("Processing")
  print(f"number of references: {sys.getrefcount(main_ref)}")

process_data(data_ref)
main_ref = None


