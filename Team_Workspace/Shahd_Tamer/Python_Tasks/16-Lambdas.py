# Custom Sorter
# Scenario: You have a list of robot speeds. You want to sort them, but not just typically (Low to High). You want to sort them High to Low (Fastest first).
# Define a list: 
speeds = [1.5, 5.5, 0.5, 3.2]
# Use the sorted() function 
#If you sort by the negative of the number (-x), the largest number becomes the smallest (most negative), so it appears first.
sorted_speeds = sorted (speeds , key= lambda val: -val )
# we can use this also ' reverse ' 
#sorted_speeds = sorted (speeds ,reverse= True ) not req 
#Output
print(f"Sorted_speeds : {sorted_speeds}")