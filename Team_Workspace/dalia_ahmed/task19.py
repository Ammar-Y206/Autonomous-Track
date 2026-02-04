
class Lidar:
    
     range = 100
     @staticmethod # to indicate that it doesnt need object 
     def print_data():
        print ("Lidar Range: ",Lidar.range)

class Sonar:
    
     range = 5

     def print_data():
         print ("sonar Range: ",Sonar.range)

Lidar.print_data()
Sonar.print_data()
# note : to create object we should put self and when typing this code (they are func not methods)