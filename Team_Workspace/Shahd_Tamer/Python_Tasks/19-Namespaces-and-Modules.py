# The Twin Sensors
# Scenario: You are merging code from two different teams in one file.

class Lidar :
    range = 100
    @staticmethod
    def print_data():
        print(f"Lidar Range: {Lidar.range}")

class Sonar:
    range = 5
    @staticmethod
    def print_data():
        print(f"Sonar Range:{Sonar.range}")

# Main
def main ():
    Lidar.print_data()
    Sonar.print_data()

if __name__ == '__main__':
    main()