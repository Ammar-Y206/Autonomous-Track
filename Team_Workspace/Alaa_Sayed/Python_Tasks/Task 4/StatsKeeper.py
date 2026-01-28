volts = [12.5, 11.8, 13.1, 12.0]

def find_extremes(list):
  return min(list) , max(list)

min_v, max_v = find_extremes(volts)
print(f"minimum value is {min_v} and maximum value is {max_v}")