
class BigObject:
    def __init__(self):
        print("born")
    def __del__(self):
        print("died")

database=[]
for i in range(3):
    m=BigObject()
    database.append(m)
    print ("End of Loop")

print ("Clearing Database...")
database.clear()
print("end of program")
# the last died appeared after end of program because the obj3 (end of list) which two refs so it destroyed when m vanishes (after the program finishes)