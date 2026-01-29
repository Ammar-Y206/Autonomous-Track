
temps = [35.5, 30.0, 32.2, 40.0, 38.1]

def get_sum(temps):
 total_sum = 0.0
 for temp in temps:
    total_sum+=temp
 return total_sum

def get_average(sum,temps):
  return sum/len(temps)


print("sum is ",get_sum(temps))
print("average is",get_average(get_sum(temps),temps))
