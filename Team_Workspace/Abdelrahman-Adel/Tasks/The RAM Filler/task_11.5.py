class BigObject:
    def __init__(self):
        print("Born")

    def __del__(self):
        print("Died")
database = []
for _ in range(3):
    obj = BigObject()
    database.append(obj)

print("End of Loop")
print("Clearing Database...")
database.clear()

print("Program End")
