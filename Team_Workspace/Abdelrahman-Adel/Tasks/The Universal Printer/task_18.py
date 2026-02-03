from typing import Any

def log_info(data: Any):
    print(f"[SYSTEM LOG]: {data}")
robot_id = 101
log_info(robot_id)

battery = 12.5
log_info(battery)

status = "Ready"
log_info(status)

values = [1, 2]
log_info(values)
