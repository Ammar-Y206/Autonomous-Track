
# Concept 17: std::function (Storing Logic)

## 1. Deep Explanation (The Logic)
Normally, a variable holds **Data** (`int x = 5`).
A `std::function` is a variable that holds **Code**.

* **The Concept:** It is a **"Universal Container"** for anything that can be called like a function.
* **Flexibility:** You can create a variable named `my_job`.
    * Today, you can put a "Print Function" inside `my_job`.
    * Tomorrow, you can put a "Math Lambda" inside `my_job`.
    * When you run `my_job()`, it just executes whatever is currently inside.



---

## 2. Why do we use it? (Callbacks)
**The "Don't Call Us, We'll Call You" Principle:**

In robotics, we often write a generic **"Button Handler"** class. This class doesn't know what the button does (Launch missile? Turn on light?).
1.  We give the class a `std::function` variable.
2.  The user injects their specific logic into that variable.
3.  When the button is pressed, the class just runs the variable.

---

## 3. Syntax & Rules
You must include: `#include <functional>`

### The Signature:
You must define what the function looks like (Return type and Arguments).
`std::function< RETURN_TYPE ( ARGUMENT_TYPES ) >`

```cpp
// A variable that can hold ANY function that takes an int and returns void
std::function<void(int)> callback;

```

---

## 4. The Trap: "The Empty Call" ⚠️

Just like a pointer, a `std::function` can be empty.

* **The Bug:** You declare `std::function<void()> f;` but don't assign anything to it.
* **The Crash:** If you try to call `f()`, the program throws a `std::bad_function_call` exception and crashes.
* **The Fix:** Always check if it is valid before calling: `if (f) f();`

---

## 5. Code Example

```cpp
#include <iostream>
#include <functional> // REQUIRED

// A normal function
void turnOnLight(int brightness) {
    std::cout << "Light ON at level " << brightness << "\n";
}

int main() {
    // 1. Create the container
    // It can hold any function that takes an 'int' and returns 'void'
    std::function<void(int)> action;

    // 2. Assign a Standard Function
    action = turnOnLight;
    action(50); // Calls turnOnLight(50)

    // 3. Assign a Lambda (The logic changes dynamically!)
    action = [](int v) {
        std::cout << "Motor Speed set to " << v << " RPM\n";
    };
    action(100); // Now it calls the Lambda logic

    // 4. Safety Check
    std::function<void(int)> empty_action;
    
    // Always check before calling
    if (empty_action) {
        empty_action(10);
    } else {
        std::cout << "Safety: Variable is empty. Did not call.\n";
    }

    return 0;
}

```

---

## 6. ROS2 Context: "Storing Callbacks"

In ROS2, `std::function` is how the system stores your logic.

When you create a Subscriber, the function signature looks like this:

```cpp
// ROS2 internal logic (simplified)
void create_subscription(TopicName, std::function<void(MsgType)> callback);

```

*ROS2 says: "Give me the code you want me to run when a message arrives. I will store it in a `std::function` and run it later."*

---

## 7. Task: "The Programmable Button" ✅

**Scenario:**
You are building a generic "Emergency Button" class. The button can be configured to do different things (Stop Motors, Sound Alarm, or Reboot).

**Requirements:**

1. Define a type `std::function<void()>` named `emergency_protocol`.
2. **The Logic Puzzle:**
* Create a function `void stopMotors() { cout << "Motors Stopped"; }`.
* Assign `stopMotors` to your `emergency_protocol` variable.
* Call the variable. (Output should be "Motors Stopped").
* **Re-assign** the variable to a **Lambda** that prints "ALARM SOUNDING!".
* Call the variable again.



**Goal:**
This proves you can swap the behavior of a system at runtime without changing the system's core code.
