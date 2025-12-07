
# Concept 2: Control Flow (If-Else & Switch Case)

## 1. Deep Explanation (The Logic)
By default, code runs linearly: line 1, then line 2, then line 3.
**Control Flow** allows the program to make decisions and "branch" into different paths based on the current situation.

There are two main tools for this:

* **If / Else:** Checks a **Boolean Condition** (True or False). It is used for complex logic, ranges, or multiple variables.
    * *Logic:* "Is the distance less than 5? If yes, stop."
* **Switch Case:** Checks a **Discrete Value** (Equality). It compares a single variable against a list of specific "labels" (Cases).
    * *Logic:* "What is the current gear? Is it 1, 2, or R?"

---

## 2. Why do we use it?
* **Reactivity:** A robot without control flow is just a scripted machine. Control flow allows the robot to react to sensors (e.g., "If obstacle detected, turn left").
* **State Management:** Robots often have states (Idle, Docking, Charging). **Switch cases** are the standard way to organize these distinct behaviors.

---

## 3. Syntax & Rules

### A. If / Else If / Else
Used when conditions are ranges (`<`, `>`) or complex logic (`&&`, `||`).

```cpp
if (condition) {
    // Runs if true
} else if (other_condition) {
    // Runs if first is false AND this is true
} else {
    // Runs if everything else is false
}
````

### B. Switch Case

Used when checking a single **integer** or **character** against specific values.

  * **Limitation:** You cannot use switch with Strings or Ranges (you can't say `case > 10`).
  * **The `break` Keyword:** Crucial. It tells the code to stop and exit the switch block. Without it, the code "falls through" to the next case automatically.

<!-- end list -->

```cpp
switch (variable) {
    case 1:
        // Code for 1
        break; // Exit
    case 2:
        // Code for 2
        break;
    default:
        // Runs if no case matches (like 'else')
        break;
}
```

-----

## 4\. The Trap: "The Forgotten Break" ⚠️

In a switch statement, if you forget to write `break;`, the computer does **not** stop. It continues executing the code for the next case as well.

  * **Scenario:** You have **Case A** (Turn Left) and **Case B** (Drive Forward).
  * **Bug:** You trigger Case A but forget `break`.
  * **Result:** The robot turns left **AND** immediately drives forward, potentially hitting the wall it was trying to avoid.

-----

## 5\. Code Example

```cpp
#include <iostream>

int main() {
    int robot_mode = 2;       // 1=Idle, 2=Auto, 3=Manual
    double battery_level = 15.5;

    // --- Part 1: Switch (State Management) ---
    // We check a specific integer value
    switch (robot_mode) {
        case 1:
            std::cout << "State: IDLE. Waiting..." << std::endl;
            break;

        case 2:
            std::cout << "State: AUTONOMOUS DRIVING." << std::endl;
            
            // --- Part 2: If-Else (Logic Check inside a case) ---
            // We check a range/condition
            if (battery_level < 20.0) {
                std::cout << "WARNING: Low Battery! Returning to dock." << std::endl;
            } else {
                std::cout << "Battery OK. Continuing mission." << std::endl;
            }
            break; // Don't forget this!

        case 3:
            std::cout << "State: MANUAL CONTROL." << std::endl;
            break;

        default:
            std::cout << "ERROR: Unknown Mode ID!" << std::endl;
            break;
    }

    return 0;
}
```

-----

## 6\. ROS2 Context: "State Machines & Callbacks"

1.  **Lifecycle Management:** ROS2 nodes have a specific "Lifecycle" (Unconfigured, Inactive, Active, Finalized). Developers use **Switch Cases** extensively to handle what the node should do in each state.
2.  **Subscriber Logic:** Inside a callback function (when data arrives), you use **If-Else** to filter bad data.
      * *Example:* "If the Lidar gives a value of `inf` (infinity), ignore it. Else, process it."

-----

## 7\. Task: The "Robot Gearbox" ✅

**Scenario:**
You are writing the transmission logic for a rover. The rover has a variable `char gear` and a variable `double speed`.

**Requirements:**

1.  Define `char gear = 'D';` (Options: 'P' for Park, 'D' for Drive, 'R' for Reverse).
2.  Define `double speed = 0.0;`.

**The Logic Puzzle:**
Use a **Switch Statement** to check the gear.

  * **Case 'P':** Set speed to 0. Print "Parking".
  * **Case 'D':** Set speed to 10. Print "Driving Forward".
  * **Case 'R':** Set speed to -5. Print "Reversing".
  * **Default:** Set speed to 0. Print "Error: Unknown Gear".

**The Trap (Experiment):**

1.  Intentionally **remove** the `break;` statement inside **Case 'D'**.
2.  Run the code with `gear = 'D'`.
3.  **Observation:** The output will likely say "Driving Forward" AND "Reversing", and the final speed will be -5 (Reverse) instead of 10. This shows why `break` is critical.
4.  **Fix:** Put the `break` back and confirm the speed is 10.
