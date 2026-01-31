temps = [35.5, 30.0, 32.2, 40.0, 38.1]
total_sum = 0.0

for t in temps:
    total_sum += t

average_temp = total_sum / len(temps)
print(f"Average Temperature: {average_temp}")
