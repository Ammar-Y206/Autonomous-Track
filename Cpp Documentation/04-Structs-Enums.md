
# Concept 4: Structs, Enums & Passing by Reference

## 1. Deep Explanation (The Logic)
We are now building the **"Vocabulary"** of our robot's code. This section combines three concepts to show you how to structure data efficiently.



### A. Structs (The "Data Bag")
A **Struct** allows you to bundle different types of variables into one package.
* **Without Struct:** You carry an Apple, a Pen, and a Book separately in your hands.
* **With Struct:** You put them all in a **Backpack**. You just pass the Backpack around.
* **Memory:** It reserves a block of memory large enough to hold all the variables inside it.

### B. Enums (The "Labels")
Computers like numbers (0, 1, 2). Humans like words (STOP, GO, WAIT).
An **Enum** (Enumeration) maps readable names to integers.
* Instead of writing `if (robot_mode == 2)`, you write `if (robot_mode == EMERGENCY)`.
* This removes **"Magic Numbers"** from your code, making it readable and less buggy.

### C. The Combination (Structs + References)
Structs often become large (holding Lidar data, GPS, etc.).
* If you pass a Struct to a function normally, C++ **Copies** the whole bag (Slow 🐢).
* We almost always pass Structs by **Reference (`&`)**. This gives the function access to the **original bag** instantly without copying (Fast ⚡).

---

## 2. Why do we use it?
* **State Machines (Enums):** Robots always have states (Idle, Docking, Charging). Enums are the standard way to manage this.
* **Clean Interfaces (Structs):** Instead of a function taking 10 parameters (`func(x, y, z, r, p, y, vel...)`), we create a Struct `State` and pass just one parameter (`func(State &s)`).
* **Efficiency (References):** Sending a CameraImage struct by Reference saves megabytes of RAM copying per frame.

---

## 3. Syntax & Rules

### A. Defining an Enum (Scoped)
Use `enum class` (Modern C++) to prevent name conflicts.
```cpp
enum class State {
    IDLE,   // Effectively 0
    RUNNING,// Effectively 1
    ERROR   // Effectively 2
};
````

### B. Defining a Struct

```cpp
struct RobotData {
    int id;
    double voltage;
    State current_state; // Using the Enum inside the Struct
};
```

### C. Passing by Reference

```cpp
// We use '&' to avoid copying the heavy struct
void updateRobot(RobotData &data) {
    data.voltage = 12.0; // Modifies the original
}
```

-----

## 4\. The Trap: "Magic Numbers" ⚠️

A **"Magic Number"** is a raw number in code with no explanation.

  * **Bad Code:** `if (state == 3) { ... }`
      * *Problem:* What is 3? Is it "Error"? Is it "Shutdown"? If you come back in 6 months, you won't know.
  * **Good Code:** `if (state == State::SHUTDOWN) { ... }`

-----

## 5\. Code Example

```cpp
#include <iostream>
#include <string>

// 1. Define the States (Labels)
enum class ConnectionState {
    DISCONNECTED, // 0
    CONNECTING,   // 1
    CONNECTED,    // 2
    FAILED        // 3
};

// 2. Define the Data Package (Struct)
struct WifiModule {
    std::string ip_address;
    int signal_strength;
    ConnectionState status; // Putting the Enum inside
};

// 3. Function taking the Struct by REFERENCE
// We modify the original struct directly using '&'
void attemptConnection(WifiModule &mod) {
    std::cout << "Connecting to " << mod.ip_address << "...\n";
    
    // Simulate logic
    if (mod.signal_strength > 50) {
        mod.status = ConnectionState::CONNECTED;
    } else {
        mod.status = ConnectionState::FAILED;
    }
}

// Helper to print Enum (Since C++ doesn't print names automatically)
// Note: We use 'const &' because we just want to READ, not modify.
void printStatus(const WifiModule &mod) {
    switch (mod.status) {
        case ConnectionState::CONNECTED: std::cout << "Status: ONLINE\n"; break;
        case ConnectionState::FAILED:    std::cout << "Status: ERROR\n"; break;
        default:                         std::cout << "Status: WAITING\n"; break;
    }
}

int main() {
    // Initialize Struct
    WifiModule my_wifi = {"192.168.1.50", 80, ConnectionState::DISCONNECTED};

    printStatus(my_wifi); // Prints WAITING

    // Pass by Reference (Original 'my_wifi' is modified)
    attemptConnection(my_wifi); 

    printStatus(my_wifi); // Prints ONLINE

    return 0;
}
```

-----

## 6\. ROS2 Context: "Goal Responses"

ROS2 uses this pattern everywhere.

1.  **Enums for Results:** When you ask a navigation robot to move, it returns an Enum code:
      * `GoalStatus::SUCCEEDED`
      * `GoalStatus::ABORTED`
      * `GoalStatus::CANCELED`
2.  **Structs for Config:** You often define a Struct to hold your robot's configuration (PID constants, Max Speed, Wheel Radius) and pass this struct to your setup functions by Reference.

-----

## 7\. Task: The "Traffic Light" Logic ✅

**Scenario:**
You are simulating a traffic light controller. You need to switch the lights in order.

**Requirements:**

1.  Define an Enum named `LightColor` with values: `RED`, `YELLOW`, `GREEN`.
2.  Define a Struct named `TrafficLight` containing:
      * `LightColor color;`
      * `int timer_seconds;`
3.  Define a Function `void updateLight(TrafficLight &light)`.

**The Logic Puzzle:**
Inside the function, check the current color and switch to the next one:

  * If `RED` $\rightarrow$ Change to `GREEN`, set timer to 30.
  * If `GREEN` $\rightarrow$ Change to `YELLOW`, set timer to 5.
  * If `YELLOW` $\rightarrow$ Change to `RED`, set timer to 60.

**In Main:**

1.  Create a `TrafficLight` variable starting at `RED`.
2.  Call `updateLight` twice.
3.  Print the final state (Should be `YELLOW` if you called it twice).

*Goal: This proves you can manipulate the "State" of an object using Enums and References.*
