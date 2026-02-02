class Logger:
  def __init__(self):
    print("--- LOG STARTED ---")

  def __del__(self):
    print("--- LOG SAVED & CLOSED ---")

class Main:
  print("Step 1")    
  
  def test_scope():
    obj = Logger()
    print("Step 2 (Inside the function)")

  test_scope()
  print("Step 3 (Outside Function)")  
    