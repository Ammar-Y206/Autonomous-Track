# The Programmable Button
# Scenario: You are building a generic "Emergency Button" system. The button can be configured to do different things (Stop Motors, Sound Alarm, or Reboot).
emergency_protocol = None
def stop_motors():
    print ("Motors Stopped")

emergency_protocol = stop_motors # Callback here is stop_motrs
 
 #Call the variable
emergency_protocol()

#Re-assign the variable to a Lambda that prints "ALARM SOUNDING!".
emergency_protocol = lambda  : print ("ALARM SOUNDING!")  # Callback here is lambda

#Call the variable again
emergency_protocol()