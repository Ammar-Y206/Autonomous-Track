from typing import TypeVar
T=TypeVar('T')
class sensor:
    def __init__(self,data:T):
        self.data=data
