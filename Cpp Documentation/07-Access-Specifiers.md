
### **Concept 7: Access Specifiers (Public, Private, Protected)**

#### **1. Deep Explanation (The Logic)**

In OOP, we don't want every part of the code to touch every variable. If a variable is critical (like the robot's main voltage), we want to lock it away so no one changes it accidentally.

Access Specifiers are keywords that set the **Visibility** of class members:

1.  **`public` (The Storefront):**
      * **Who can access?** Everyone. The main program, other classes, anyone.
      * **Usage:** This is the "User Interface." Functions like `startEngine()` or `getSpeed()`.
2.  **`private` (The Engine Room):**
      * **Who can access?** Only the class itself.
      * **Usage:** Internal variables and logic. For example, the specific voltage on Pin 13. The user shouldn't touch this directly; they should use a Public function to request a change.
3.  **`protected` (The Family Secret):**
      * **Who can access?** The class itself **AND** any class that Inherits from it (Child classes).
      * **Usage:** Used in Inheritance. It’s too dangerous to be Public, but we want our "Children" classes to use it.

-----

#### **2. Why do we use it? (Encapsulation)**

  * **Safety:** Imagine a `Motor` class. If the internal variable `pwm_value` is `public`, a lazy programmer might write `motor.pwm_value = 99999;` in `main()`, burning the motor.
  * **Encapsulation:** If we make `pwm_value` `private`, the programmer is forced to use `motor.setSpeed(100)`. Inside `setSpeed`, we write logic: "If value \> 255, set to 255." This protects the hardware.

-----

#### **3. Syntax & Rules**

Inside a class, you group code under these labels.

```cpp
class Robot {
public:
    // Accessible by main()
    void bootUp() { startInternalSystems(); }

protected:
    // Accessible by "Drone" or "Car" classes that inherit from Robot
    int hardware_id;

private:
    // Accessible ONLY by functions inside 'Robot'
    // HIDDEN from main() and HIDDEN from Child classes
    double internal_voltage;
    
    void startInternalSystems() {
        internal_voltage = 12.0; // OK: We are inside the class
    }
};
```

-----

#### **4. The Trap: "The Lazy Public"**

Beginners often make everything `public` because "it's easier."

  * **The Bug:** You have a variable `bool is_connected`.
  * **Bad Code:** In `main()`, you write `wifi.is_connected = true;`.
  * **Result:** You changed the flag, but you didn't actually run the code to connect to the router\! The robot thinks it's online, but it isn't.
  * **Fix:** Make `is_connected` `private`. Force the user to call `wifi.connect()`, which handles the logic and *then* sets the flag.

-----

#### **5. Code Example**

```cpp
#include <iostream>

class SafeMotor {
private: 
    // DATA IS PRIVATE
    // No one outside can mess with this variable directly.
    int speed_limit = 100;
    int current_speed = 0;

public:
    // INTERFACE IS PUBLIC
    // This provides a safe way to set speed.
    void setSpeed(int s) {
        if (s > speed_limit) {
            std::cout << "Error: " << s << " exceeds limit! Clamped to " << speed_limit << ".\n";
            current_speed = speed_limit;
        } else if (s < 0) {
            std::cout << "Error: Negative speed not allowed. Stopping.\n";
            current_speed = 0;
        } else {
            current_speed = s;
            std::cout << "Speed set to: " << current_speed << "\n";
        }
    }

    int getSpeed() {
        return current_speed;
    }
};

int main() {
    SafeMotor m;

    // m.current_speed = 500; // COMPILER ERROR! Private variable.
    // m.speed_limit = 200;   // COMPILER ERROR! Private variable.

    // Correct Usage
    m.setSpeed(50);   // Works
    m.setSpeed(200);  // Triggers internal safety check
    
    return 0;
}
```

-----

#### **6. ROS2 Context: "Node Privacy"**

In ROS2, we write Nodes as classes.

  * **Private Members:** Variables like `rclcpp::Publisher` and `rclcpp::Subscription` are almost always **Private**.
      * *Why?* No other part of the code needs to manually touch the publisher pointer. They just need the node to do its job.
  * **Public Members:** The Constructor (to start the node) and maybe some "Getter" functions.
  * **Protected:** Rarely used unless you are building a complex library of Robots where a `FlyingRobot` inherits from a generic `RobotBase`.

-----

#### **7. Task: The "Bank Vault"**

**Scenario:**
You are creating a class for a Bank Account (or a Robot's Power Budget).

**Requirements:**

1.  Create a class `Account`.
2.  **Private Variable:** `double balance` (Initialize to 0.0).
3.  **Public Method:** `void deposit(double amount)`.
      * Logic: If amount \> 0, add to balance. Else, print "Invalid amount".
4.  **Public Method:** `double withdraw(double amount)`.
      * Logic: If amount \<= balance, subtract and return the amount. Else, print "Insufficient funds" and return 0.
5.  **The Logic Puzzle (Main):**
      * Create an `Account` object.
      * **Try to cheat:** Write `my_account.balance = 1000000;`.
      * **Observe:** The compiler will yell at you (Error: `balance` is private).
      * **Fix:** Use `deposit(100)` and `withdraw(50)` to interact with the object legally.

**Goal:** This proves that `private` prevents "hacking" or accidental modification of internal data.
