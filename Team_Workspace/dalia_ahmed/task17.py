
emergency_protocol = None
def stop_motors(): 
    print("Motors Stopped")
emergency_protocol=stop_motors
emergency_protocol()
emergency_protocol=lambda:print("ALARM SOUNDING!")
emergency_protocol()