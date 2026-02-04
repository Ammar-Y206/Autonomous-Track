
def log_info(data: any):
    print("[SYSTEM LOG]: ",data)


id=101
log_info(id)
battery=12.5
log_info(battery)
status = "Ready"
log_info(status)
list = [1, 2]
log_info(list)

# we use type hinting as a documention (warning phrases before crashing)but it doesnt affect the run time (like mypy (command line) in large projects)
# from typing import TypeVar
# def add(a:T,b:T) -> T: # to confirm they have the same type, -> to return the same type
