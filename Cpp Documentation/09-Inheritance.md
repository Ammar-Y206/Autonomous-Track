
# Concept 9: Inheritance (The Hierarchy)

## 1. Deep Explanation (The Logic)
Inheritance is the concept of **"Genetic Evolution"** for code.
Instead of creating every class from scratch, you take an existing class (the **Parent**) and create a new class (the **Child**) that inherits all its features.



* **Parent Class (Base):** The general blueprint (e.g., `Vehicle`).
* **Child Class (Derived):** The specific version (e.g., `Car`, `Boat`).

**The Logic:** A `Car` **IS A** `Vehicle`. Therefore, the `Car` automatically gets everything the `Vehicle` has (speed, fuel, engine) without you typing it again. It then adds its own special features (wheels, steering wheel).

---

## 2. Why do we use it?
1.  **Code Reusability (Don't Repeat Yourself):**
    * If you have `Drone`, `Rover`, and `Submarine`, they all share `battery_level` and `turnOn()`.
    * Instead of writing `turnOn()` 3 times, write it **once** in a `Robot` parent class. All three children get it for free.
2.  **Organization:** It creates a logical hierarchy. You can fix a bug in the Parent, and all Children are automatically fixed.

---

## 3. Syntax & Rules
To inherit, use a colon `:` followed by the access level (usually `public`) and the Parent name.

```cpp
// 1. Parent Class
class Parent {
    // ... logic ...
};

// 2. Child Class
// "Child inherits everything publicly from Parent"
class Child : public Parent {
    // ... new logic ...
};
````

### Access Rules inside Child Class:

  * **Public members of Parent:** Become **Public** in Child (Everyone can use them).
  * **Protected members of Parent:** Become **Protected** in Child (Only Child can use them).
  * **Private members of Parent:** Remain **Private** in Parent (Child cannot touch them directly).

-----

## 4\. The Trap: "Is-a" vs. "Has-a" ⚠️

Do not use Inheritance for everything.

**The Rule:** Use Inheritance only if the Child **IS A** version of the Parent.

  * ✅ **Correct:** `Dog` inherits `Animal` (A dog **is an** animal).
  * ❌ **Wrong:** `Car` inherits `Engine` (A car **is not** an engine).
  * **The Fix:** If a Car **HAS A** Engine, put the `Engine` class inside the `Car` class as a variable (Composition).

-----

## 5\. Code Example

```cpp
#include <iostream>
#include <string>

// --- Parent Class (The General Blueprint) ---
class Robot {
protected:
    // Protected: Visible to Children (Drone), but hidden from Main.
    int battery_level;

public:
    Robot() { 
        battery_level = 100; 
    }

    void reportStatus() {
        std::cout << "[Robot System] Battery: " << battery_level << "%\n";
    }
};

// --- Child Class (The Specific Version) ---
// Syntax: class Name : public Parent
class Drone : public Robot {
public:
    // Drone has everything 'Robot' has, plus this:
    void takeOff() {
        if (battery_level > 20) {
            // We can access 'battery_level' because it is Protected
            battery_level -= 10; 
            std::cout << ">> Drone Taking Off! Whoosh!\n";
        } else {
            std::cout << ">> Battery too low to fly.\n";
        }
    }
};

int main() {
    Drone my_drone;

    // 1. Calling a Child method
    my_drone.takeOff(); 

    // 2. Calling a Parent method
    // 'reportStatus' is not in Drone, but Drone inherited it from Robot!
    my_drone.reportStatus();

    return 0;
}
```

-----

## 6\. ROS2 Context: "The Ultimate Parent"

Inheritance is the foundation of ROS2 code.
Every Node you write is a **Child** of the standard ROS2 system.

1.  **The Parent:** `rclcpp::Node`
      * This class, written by the ROS2 developers, contains thousands of lines of code to handle networking, timers, parameters, and communication.
2.  **The Child:** `MyLidarNode`
      * You write: `class MyLidarNode : public rclcpp::Node`
3.  **Result:** Your simple class instantly gains the ability to talk to other robots, manage time, and log data, because it inherited those superpowers from `rclcpp::Node`.

-----

## 7\. Task: "The Vehicle Factory" ✅

**Scenario:**
You are building a simulation with different types of vehicles.

**Requirements:**

1.  Create a Parent Class named `Vehicle`.
      * **Protected Variable:** `double speed`.
      * **Public Method:** `void setSpeed(double s)` (Sets the speed).
      * **Public Method:** `void showSpeed()` (Prints "Current Speed: X").
2.  Create a Child Class named `SportsCar` that inherits from `Vehicle`.
      * **Public Method:** `void turboBoost()`.
      * **Logic:** Inside turboBoost, multiply the inherited `speed` by 2 and print "TURBO ACTIVATED\!".

**In Main:**

1.  Create a `SportsCar` object.
2.  Call `setSpeed(50)` (Parent function).
3.  Call `turboBoost()` (Child function).
4.  Call `showSpeed()` (Parent function).

**Expected Output:**

```text
TURBO ACTIVATED!
Current Speed: 100
```

*Note: If you see 100, it proves the Child successfully modified the Parent's variable.*


