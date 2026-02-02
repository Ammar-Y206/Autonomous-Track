
dict={
}
dict["Wheel"]=4
dict["Motor"]=2

dict["Sensor"]=5

dict["Wheel"]-=1
print(dict["Wheel"])
dict["Motor"]+=3
print(dict["Motor"])
print(dict.get("laser",0)) # returns 0 if it doesnt exist 

