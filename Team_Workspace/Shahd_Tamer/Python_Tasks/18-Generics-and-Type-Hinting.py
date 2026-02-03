# The Universal Printer
# Scenario: You are building a debugging tool. You need a single function that can take any variable (ID, Speed, Name) and print it with a formatted log prefix.
from typing import  Any
def log_info(data: Any):
    print (f"Print [SYSTEM LOG]:{data} ")

id = 101
log_info(id)

battery = 12.5
log_info(battery)

status = "Ready"
log_info(status)

list = [1, 2]
log_info(list)