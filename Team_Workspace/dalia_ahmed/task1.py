
def calc_dist(time):
 dist_cm=float(time)/58
 dist_meter=dist_cm/100
 return dist_meter
#apply it
time_mircoseconds=5882
print ("result",calc_dist(time_mircoseconds))

