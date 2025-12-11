
# Concept 10: Polymorphism (Overrides)

## 1\. Deep Explanation (The Logic)

Polymorphism (Greek for "Many Shapes") allows different objects to respond to the **same command** in their own unique way.

**Imagine you have a Drone and a Rover.**

  * They move differently (Fly vs. Roll).
  * However, you want to treat them both simply as "Robots."

### The Problem vs. Solution:

In C++, you have to explicitly mark functions as `virtual` to get this behavior.
**In Python, Polymorphism is automatic.** You don't need special keywords like `virtual`. If a Child class has a method with the same name as the Parent, Python **always** uses the Child's version (this is called **Overriding**).

  * **Duck Typing:** Python follows a philosophy called "Duck Typing": *"If it walks like a duck and quacks like a duck, treat it like a duck."*
      * You can create a list of completely different objects (a `Car`, a `Cat`, and a `Cloud`). As long as they all have a method named `move()`, Python will happily loop through them and call `move()` on each one without crashing.

-----

## 2\. Why do we use it? (The "Universal Interface")

1.  **Scalability:**
      * You can write a function `shutdown_all(robot_list)`.
      * It loops through the list calling `stop()`.
      * The Drones land, the Rovers brake, and the Arms lock. The function doesn't need to know *what* they are, only that they have a `stop()` method.
2.  **Hardware Abstraction:**
      * In ROS2, you might have a base class `Sensor`.
      * You can swap a `RealLidar` with a `SimulatedLidar` without changing a single line of your main algorithm, as long as both have a `read_data()` function.

-----

## 3\. Syntax & Rules

### A. The Parent (Base Class)

Define the method normally. Usually, in the base class, we just `pass` or raise an error to indicate "this must be replaced."

```python
class Robot:
    def move(self):
        print("Robot moving generic...")
```

### B. The Child (Derived Class)

Just define the same function name. No `override` keyword is needed (though you can use type hints/comments for clarity).

```python
class Drone(Robot):
    # This automatically replaces the Parent's 'move'
    def move(self):
        print("Drone is Flying!")
```

-----

## 4\. The Trap: "The Forgotten Method" ⚠️

Since Python doesn't force you to write `virtual`, a different bug appears.

  * **Scenario:** You have a `Drone` class, but you accidentally name the function `fly()` instead of `move()`.
  * **Action:** You put the Drone in a list of Robots and call `robot.move()`.
  * **Result:** Python looks for `move()` in the Drone. It doesn't find it. It goes up to the Parent (`Robot`) and runs the **generic** `move()` code. Your drone tries to roll on the ground instead of flying.

-----

## 5\. Code Example

```python
# --- 1. The Interface (Abstract Idea) ---
class Sensor:
    def read_data(self):
        # This is a placeholder. 
        # In a real interface, we might raise NotImplementedError
        print("[Base] Reading generic data...")

# --- 2. Specific Implementations ---
class Lidar(Sensor):
    def read_data(self):
        # This OVERRIDES the parent method
        print("[Lidar] Scanning 360 degrees for obstacles.")

class Camera(Sensor):
    def read_data(self):
        # This OVERRIDES the parent method
        print("[Camera] Capturing RGB image.")

# --- 3. The Power of Polymorphism ---
def main():
    my_lidar = Lidar()
    my_cam = Camera()

    # We create a list containing different types of sensors
    # Python doesn't care that they are different classes
    sensor_list = [my_lidar, my_cam]
    
    print("--- System Update ---")
    
    # We loop through them as generic "Sensors"
    for s in sensor_list:
        # Python checks: "Does this object have a 'read_data' method?"
        # Yes? Run it.
        s.read_data()

if __name__ == "__main__":
    main()
```

-----

## 6\. ROS2 Context: "Lifecycle Nodes"

ROS2 uses this for **Managed Nodes (Lifecycle)**.

1.  **The Concept:** ROS2 provides a base class called `LifecycleNode`. It has empty methods like `on_configure`, `on_activate`.
2.  **Your Job:** You create your node and **Override** these methods.
3.  **The Result:**
      * When the ROS2 system sends the "Configure" signal, it triggers **your** specific `on_configure` function to connect to hardware.
      * When it sends "Activate", it triggers **your** specific `on_activate` function to start publishing data.

-----

## 7\. Task: "The Payment Gateway" ✅

**Scenario:**
You are building a vending machine that accepts different payment methods.

**Requirements:**

1.  **Base Class:** `PaymentMethod`
      * Function: `pay(self, amount)`
      * Default behavior: Print "Generic Payment".
2.  **Derived Class:** `CreditCard`
      * Override `pay`: Print "Processing Credit Card: $[amount]".
3.  **Derived Class:** `Cash`
      * Override `pay`: Print "Accepting Cash: $[amount]".

**The Logic Puzzle (Main):**

1.  Create a variable `method` and assign it a `CreditCard` object.
2.  Call `method.pay(15.0)`.
3.  **Switch it:** Now assign `method` a `Cash` object.
4.  Call `method.pay(5.0)`.

**Success Condition:**

  * First print: **"Processing Credit Card..."**
  * Second print: **"Accepting Cash..."**
  * This proves that the variable `method` can change its behavior (shape-shift) based on what object it holds.
