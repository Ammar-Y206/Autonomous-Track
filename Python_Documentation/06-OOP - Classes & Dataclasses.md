
# Concept 6: OOP - Classes & Dataclasses

## 1\. Deep Explanation (The Logic)

Up until now, we have used simple variables scattered around the code. But in robotics, we deal with complex physical objects like **Motors**, **Sensors**, and **Batteries**.

### The Concept:

A **Class** is a Custom Data Type. It is a **"Blueprint"** or **"Template"** that groups two things together:

1.  **Attributes (Data):** Variables that describe the object (e.g., `voltage`, `speed`, `name`).
2.  **Methods (Behaviors):** Functions that the object can perform (e.g., `turn_on()`, `read_data()`).

### Struct vs. Class (In Python)

Python does not have a native `struct` keyword like C++, but we differentiate them by how we use them:

  * **Dataclass (The Struct Equivalent):** Used for **Passive Data**. It’s a "Bag of Variables" with no complex logic.
      * *Example:* A GPS Coordinate point (x, y, z).
  * **Standard Class:** Used for **Active Objects**. It has internal logic, initialization steps, and methods.
      * *Example:* A `MotorController` that handles safety limits.

-----

## 2\. Why do we use it?

  * **Organization (Scalability):**
      * *Without OOP:* If you have 4 motors, you need variables like `motor1_speed`, `motor2_speed`, `motor1_pin`... (Messy 🤯).
      * *With OOP:* You create **one blueprint** called `Motor`. You then create 4 **Objects** from that blueprint.
  * **Encapsulation (Safety):**
      * You can "hide" internal variables so other parts of the code don't break them.
      * *Example:* You prevent the main code from setting `motor.speed = 10000` directly. Instead, you force usage of `motor.set_speed(10000)`, where the class checks if that speed is safe.

-----

## 3\. Syntax & Rules

### A. The Dataclass (Data Holder)

```python
from dataclasses import dataclass

@dataclass
class Point3D:
    x: float
    y: float
    z: float
```

### B. The Class (The Logic Machine)

In Python, we use the special variable `self` to refer to "this specific object".

```python
class Motor:
    # 1. The Constructor (Runs automatically when created)
    def __init__(self):
        # The underscore "_" hints that this is Private (Internal use only)
        self._speed = 0 

    # 2. Public Method
    def set_speed(self, s):
        if s < 100:
            self._speed = s  # Logic/Safety check
```

-----

## 4\. The Trap: "The Missing Self" ⚠️

In C++, "this" is implicit. **In Python, `self` is explicit.**

  * **The Bug:** Inside a class, if you write `speed = 10` instead of `self.speed = 10`.
  * **The Result:** Python creates a temporary local variable named `speed`, sets it to 10, and then destroys it immediately when the function ends. Your robot's actual speed variable never changes.
  * **The Fix:** Always put `self.` before variables that belong to the object.

-----

## 5\. Code Example

```python
from dataclasses import dataclass

# --- 1. Dataclass: Simple Data Grouping ---
# We use this because it's just data.
@dataclass
class BatteryStatus:
    voltage: float
    current: float
    percentage: float

# --- 2. Class: Object with Logic ---
class RoboticArm:
    # Constructor: Sets up the initial state
    def __init__(self, arm_id):
        # We use 'self' to attach these variables to the specific object
        self.name = arm_id
        
        # We use an underscore '_' to signal this is Private/Internal
        self._is_active = False 

    # Method to modify state safely
    def activate(self):
        print(f"[{self.name}] Activating Hydraulics...")
        self._is_active = True

    # Method to read state safely
    def get_status(self):
        return self._is_active

# Main Execution
# A. Using the Dataclass
bat = BatteryStatus(voltage=12.5, current=2.0, percentage=90.0)
# Direct access allowed for Dataclasses
print(f"Battery: {bat.voltage}V")

# B. Using the Class
arm1 = RoboticArm("Arm_Left")
arm2 = RoboticArm("Arm_Right")

# arm1._is_active = True  <-- BAD PRACTICE (It's marked private)

arm1.activate()  # Correct: Using Public method

print(f"Arm 1 Active: {arm1.get_status()}")
print(f"Arm 2 Active: {arm2.get_status()}")
```

-----

## 6\. ROS2 Context: "Nodes are Classes"

This is the standard structure for Python ROS2 code.

1.  **Nodes are Classes:** You don't write a script; you define a Class that inherits from `Node`.
      * *Logic:* `class MyRobotNode(Node):`
      * The `__init__` function sets up your publishers and subscribers.
2.  **Messages are Objects:** When you use `geometry_msgs.msg.Twist`, it behaves exactly like a **Dataclass** or Struct. You access data via `msg.linear.x`.

-----

## 7\. Task: The "Smart Thermostat" ✅

**Scenario:**
You are building a thermostat for a robot's CPU. You want to ensure the target temperature is never set to a dangerous level.

**Requirements:**

1.  Create a class named `Thermostat`.
2.  **Constructor (`__init__`):**
      * Initialize `self._target_temp` to 0.0.
3.  **Methods:**
      * `def set_temperature(self, temp)`:
          * **Logic:** If `temp` is greater than `100.0`, print "WARNING: Too Hot\!" and set `self._target_temp` to `100.0`.
          * Else, set `self._target_temp` to the input value.
      * `def get_temperature(self)`: Returns the current value.

**In Main:**

1.  Create an object `cpu_monitor`.
2.  Try to set temperature to `150.0`.
3.  Print the actual temperature using your getter method.

**Success Criteria:**
The output should show the warning, and the final temperature should be clamped at `100.0`.
