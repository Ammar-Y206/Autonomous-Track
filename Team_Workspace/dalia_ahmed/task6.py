
class thermostat:
    def _init_(self):
        self._target_temp=0
    def set_temperature(self, temp):
        if temp>100:
            print("WARNING: Too Hot!")
            self._target_temp=100
        else:
            self._target_temp=temp
    def get_temperature(self):
        return self._target_temp
    
cpu_monitor=thermostat()
cpu_monitor.set_temperature(150)
print("final temp: ",cpu_monitor.get_temperature())