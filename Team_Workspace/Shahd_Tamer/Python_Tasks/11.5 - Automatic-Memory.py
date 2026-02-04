# THE RAM FILLER
#cenario: You want to simulate a memory management situation. You will create a "Database" list, fill it, and then manually clear it to free space.
class BigObject :
    # Constructor
    def __init__(self):
        print(" BORN ")
    # Distructor
    def __del__(self):
        print(" DIED ")

# Main 
database = []
for i in range (3):
    database.append(BigObject())
print (" END OF LOOP ")

print ("Clearing Database...")
database.clear()
print ("Program End")