class BigObject:
  def __init__(self):
    print("Born")

  def __del__(self):
    print("Died")

  database = []
  i = 1
  while i <= 3:
    obj = BigObject()
    database.append(obj)
    i += 1

  print("End of loop")
  database.clear

  print("Ckearing Database")



    
        