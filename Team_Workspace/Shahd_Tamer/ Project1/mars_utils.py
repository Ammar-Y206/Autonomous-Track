# Mini project week 1
from typing import TypeVar
from typing import Generic
 ## Test 1  ”Universal Adapter” (Generics)
# --- 1. Define the Generic Type 'T' ---
T = TypeVar('T')
class Sensor (Generic[T]) :
    # Type hinting generics 
    def __init__(self, data :T):
        self.data = data
     # return data
    def get (self) -> T :
        return self.data