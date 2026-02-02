# TASK 1 dISTANCE SENSOR LOGIC 
# DIFINE THE VARIABLE 
time_microseconds = 5882

#USING THIS FORMULA : Distance(cm)=Time/58
Distance_cm = float (time_microseconds) / 58 
# 2nd step : Convert that result to meters (divide by 100).
Distance_meters = float(Distance_cm/100)

print (f"The Distance in (m) =  {Distance_meters } m")