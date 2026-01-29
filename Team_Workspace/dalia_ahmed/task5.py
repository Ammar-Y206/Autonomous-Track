
volts=[12.5, 11.8, 13.1, 12.0]
def find_extremes(list):
    max=list[0]
    min=list[0]
    for i in list:
        if i>max:
         max=i
        if i<min:
           min=i
    return max,min
max,min=find_extremes(volts)
print("max value",max)
print("min value",min)