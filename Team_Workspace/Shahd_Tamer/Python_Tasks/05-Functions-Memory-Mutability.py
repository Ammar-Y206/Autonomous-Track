# STATS KEEPER
#define 
volts = [12.5, 11.8, 13.1, 12.0]

#define function 
def find_extremes(data_list):
    # to calc minimum
    min_val= min (volts)
    # to calc maximum
    max_val = max (volts)
    return min_val , max_val

# Main Execution
# we put each result 'tuble 'into two variables to use any one of them after then if needed alone 
min_v, max_v = find_extremes(volts)

# print each result
print(f" VOLTS ARE : {volts}")
print(F" MIN_VAL IS {min_v}")
print(F" MAX_VAL IS {max_v}")