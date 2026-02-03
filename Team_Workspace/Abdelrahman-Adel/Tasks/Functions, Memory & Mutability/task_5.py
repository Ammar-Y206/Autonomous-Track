from enum import Enum
from dataclasses import dataclass
volts = [12.5,11.8,13.1,12.0]
def find_extrem(data_list):
    max_data = max(data_list)
    min_data = min(data_list)
    return max_data, min_data
max_v, min_v = find_extrem(volts)
print(f"Volts: {volts}")
print(f"Maximum: {max_v}")
print(f"Minimum: {min_v}")