class Lidar:
    range = 100

    @staticmethod
    def print_data():
        print(f"Lidar Range: {Lidar.range}")
class Sonar:
    range = 5

    @staticmethod
    def print_data():
        print(f"Sonar Range: {Sonar.range}")
Lidar.print_data()
Sonar.print_data()
