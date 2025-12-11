# Concept 9: Inheritance (The Hierarchy)

## 1\. Deep Explanation (The Logic)

Inheritance is the concept of **"Genetic Evolution"** for code.
Instead of creating every class from scratch, you take an existing class (the **Parent**) and create a new class (the **Child**) that inherits all its features.

  * **Parent Class (Base):** The general blueprint (e.g., `Vehicle`).
  * **Child Class (Derived):** The specific version (e.g., `Car`, `Boat`).

**The Logic:** A `Car` **IS A** `Vehicle`. Therefore, the `Car` automatically gets everything the `Vehicle` has (speed, fuel, engine) without you typing it again. It then adds its own special features (wheels, steering wheel).

-----

## 2\. Why do we use it?

1.  **Code Reusability (Don't Repeat Yourself):**
      * If you have `Drone`, `Rover`, and `Submarine`, they all share `battery_level` and `turn_on()`.
      * Instead of writing `turn_on()` 3 times, write it **once** in a `Robot` parent class. All three children get it for free.
2.  **Organization:** It creates a logical hierarchy. You can fix a bug in the Parent, and all Children are automatically fixed.

-----

## 3\. Syntax & Rules

To inherit in Python, you put the Parent's name in parentheses `()` after the Child's class name.

```python
# 1. Parent Class
class Parent:
    # ... logic ...
    pass

# 2. Child Class
# "Child inherits everything from Parent"
class Child(Parent):
    # ... new logic ...
    pass
```

### The `super()` Function

In Python, if the Child has its own `__init__` constructor, it **overwrites** the Parent's constructor. To fix this, we use `super()`.

  * **Logic:** `super().__init__()` means "Go up to my Parent and run their initialization code first, then run mine."

-----

## 4\. The Trap: "Is-a" vs. "Has-a" ⚠️

Do not use Inheritance for everything.

**The Rule:** Use Inheritance only if the Child **IS A** version of the Parent.

  * ✅ **Correct:** `Dog` inherits `Animal` (A dog **is an** animal).
  * ❌ **Wrong:** `Car` inherits `Engine` (A car **is not** an engine).
  * **The Fix:** If a Car **HAS A** Engine, put the `Engine` object inside the `Car` class as a variable (Composition).

-----

## 5\. Code Example

```python
# --- Parent Class (The General Blueprint) ---
class Robot:
    def __init__(self):
        # Protected: Visible to Children (by convention)
        self._battery_level = 100 

    def report_status(self):
        print(f"[Robot System] Battery: {self._battery_level}%")

# --- Child Class (The Specific Version) ---
# Syntax: class Child(Parent):
class Drone(Robot):
    def take_off(self):
        # Drone has everything 'Robot' has, plus this:
        if self._battery_level > 20:
            # We can access '_battery_level' because we inherited it
            self._battery_level -= 10
            print(">> Drone Taking Off! Whoosh!")
        else:
            print(">> Battery too low to fly.")

# Main Execution
my_drone = Drone()

# 1. Calling a Child method
my_drone.take_off()

# 2. Calling a Parent method
# 'report_status' is not written in Drone, but Drone inherited it from Robot!
my_drone.report_status()
```

-----

## 6\. ROS2 Context: "The Ultimate Parent"

Inheritance is the foundation of ROS2 code.
Every Node you write is a **Child** of the standard ROS2 system.

1.  **The Parent:** `Node` (from `rclpy.node`)
      * This class contains thousands of lines of code to handle networking, timers, parameters, and communication.
2.  **The Child:** `MyLidarNode`
      * You write: `class MyLidarNode(Node):`
3.  **The Magic Line:** Inside your `__init__`, you must call `super().__init__('node_name')`.
      * This tells ROS2: "Initialize all the networking stuff in the Parent class before I start adding my own sensors."

-----

## 7\. Task: "The Vehicle Factory" ✅

**Scenario:**
You are building a simulation with different types of vehicles.

**Requirements:**

1.  Create a Parent Class named `Vehicle`.
      * **Constructor:** Initialize `self._speed` to 0.0.
      * **Public Method:** `set_speed(self, s)` (Sets the speed).
      * **Public Method:** `show_speed(self)` (Prints "Current Speed: X").
2.  Create a Child Class named `SportsCar` that inherits from `Vehicle`.
      * **Public Method:** `turbo_boost(self)`.
      * **Logic:** Inside turbo\_boost, multiply the inherited `_speed` by 2 and print "TURBO ACTIVATED\!".

**In Main:**

1.  Create a `SportsCar` object.
2.  Call `set_speed(50)` (Parent function).
3.  Call `turbo_boost()` (Child function).
4.  Call `show_speed()` (Parent function).

**Expected Output:**

```text
TURBO ACTIVATED!
Current Speed: 100.0
```

*Note: If you see 100, it proves the Child successfully modified the Parent's variable.*
