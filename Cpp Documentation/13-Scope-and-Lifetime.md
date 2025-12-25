
# Concept 13: Scope & Lifetime

## 1. Deep Explanation (The Logic)
While **Scope** and **Lifetime** are related, they are not the same thing.



### Scope (Visibility - "The View") 👀
* **Definition:** The region of the code where you can **see and use** a variable by its name.
* **Rule:** Variables are usually limited by **Curly Braces `{ }`**. If you define a variable inside `{ ... }`, it is invisible outside.

### Lifetime (Duration - "The Pulse") 💓
* **Definition:** The time period during which the variable actually **exists in the Memory (RAM)**.
* **Rule:**
    * **Automatic (Stack):** Born at definition, dies at the closing brace `}`.
    * **Static:** Born when the program starts, dies when the program ends (even if the scope is local).

---

## 2. Why do we use it?
1.  **Memory Efficiency:** We don't want every variable to stay in RAM forever. When a function finishes, its local variables (`i`, `temp`, `calc`) should be destroyed to free up space.
2.  **Name Safety:** You can use the variable name `counter` in Function A and also in Function B. Because they are in different Scopes, they don't conflict.

---

## 3. Syntax & Rules

### A. Local Scope (Automatic)
Most variables are this type.
```cpp
void func() {
    int x = 5; // Scope: Starts here
} // Scope & Lifetime: Ends here. 'x' is deleted from RAM.

```

### B. Block Scope

Variables inside `if`, `for`, or `while` are trapped there.

```cpp
if (true) {
    int secret = 99;
}
// std::cout << secret; // ERROR! 'secret' does not exist here.

```

### C. Static Lifetime (The Exception) ⚡

Using the keyword `static` inside a function keeps the variable **Alive in RAM**, but still keeps its visibility **Private to that function**.

```cpp
void counter() {
    static int count = 0; // Born once. Never dies.
    count++; // It remembers the value from the previous call!
}

```

---

## 4. The Trap: "The Dangling Reference" ⚠️

This is a fatal bug related to lifetime.

* **Scenario:** You write a function that creates a local variable `int x = 10`.
* **The Mistake:** You return a Pointer or Reference to `x` (`return &x`).
* **The Crash:** As soon as the function returns, `x` is destroyed (Lifetime ends). The pointer you returned now points to **dead memory**. Accessing it crashes the robot.

---

## 5. Code Example

```cpp
#include <iostream>

// 1. Global Scope
// Visible everywhere. Alive forever.
// (Avoid this in robotics unless necessary)
int global_config = 100; 

void countCalls() {
    // 2. Static Local Variable
    // Scope: Only inside this function.
    // Lifetime: Forever (it remembers value between calls).
    static int calls = 0; 
    calls++;
    std::cout << "Function called " << calls << " times.\n";
}

int main() {
    // 3. Main Scope
    int x = 10; 

    {
        // 4. Inner Block Scope
        int y = 20;
        std::cout << "Inside Block: x=" << x << ", y=" << y << "\n";
    }
    // y is now DEAD.
    // std::cout << y; // This would cause a Compiler Error.

    std::cout << "Outside Block: x=" << x << "\n";

    std::cout << "--- Static Test ---\n";
    countCalls(); // Prints 1
    countCalls(); // Prints 2 (It remembered!)
    countCalls(); // Prints 3

    return 0;
}

```

---

## 6. ROS2 Context: "The Callback Trap"

In ROS2, beginners often try to save data in a local variable inside a callback.

**Bad Code:**

```cpp
void timer_callback() {
    int counter = 0; 
    counter++; 
    // Logic: You want to count messages.
    // Reality: Every time this runs, 'counter' is recreated as 0. It never passes 1.
}

```

**The Fix:** You must make `counter` a **Class Member Variable** (Global to the class object) so its lifetime persists across multiple callback triggers.

---

## 7. Task: "The Memory Test" ✅

**Scenario:**
You need to verify exactly when variables die.

**Requirements:**

1. Create a class `Tracker`.
* **Constructor:** Print "Tracker Born".
* **Destructor:** Print "Tracker Died".


2. **In Main:**
* Print "Start".
* Create a scope `{`.
* Create a `Tracker` object named `t1`.
* Print "Inside Scope".
* End the scope `}`.
* Print "End".



**Observation:**
Does "Tracker Died" print **before** "End"?

**Concept Check:**
Try to access `t1` after the closing brace `}`. The compiler should stop you. This proves **Scope** limits visibility.

*Goal: Understand that just because your program is still running (main is active), it doesn't mean your variables (t1) are still alive.*

```
