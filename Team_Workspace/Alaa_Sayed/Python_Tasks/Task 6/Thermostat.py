class Thermostat:  

  def __init__(self):
    self._target_temp = 0.0
    

  def set_temperature(self, temp):
    if temp > 100.0:
      print("WARNING: Too Hot!")
      self._target_temp = 100
    else:
      self._target_temp = temp

  def get_temperature(self):
    return self._target_temp


cpu_monitor = Thermostat() 
cpu_monitor.set_temperature(150)
print(cpu_monitor.get_temperature())



