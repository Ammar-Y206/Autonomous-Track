
# Concept 12: Smart Pointers (Memory Safety)

## 1. Deep Explanation (The Logic)
**Raw pointers** (`int* p = new int`) are dangerous because they require **Manual Memory Management**.

* **The Problem:** If you create an object but forget to `delete` it, it stays in RAM forever. This is a **Memory Leak**. If your robot runs for 5 days, these leaks pile up until the robot crashes.
* **The Solution:** A **Smart Pointer** is a wrapper class that holds a raw pointer.
    * It acts like a raw pointer (you can use `*` and `->`).
    * **But:** It has a built-in "Destructor". When the smart pointer goes out of scope (dies), it **automatically deletes** the object it is holding.



### The Two Main Types:

#### A. `std::unique_ptr` (The Sole Owner) 🔒
* **Logic:** "I own this object. No one else can own it."
* **Rule:** You cannot copy it. You can only "move" it to someone else.
* **Use case:** A driver controlling a specific hardware port (only one driver allowed).

#### B. `std::shared_ptr` (The Shared Owner) 🤝
* **Logic:** "I own this object, but you can hold it too."
* **Mechanism:** It uses **Reference Counting**. It keeps a count of how many pointers are looking at the object.
    1.  Count starts at 1.
    2.  If you pass it to a friend, count = 2.
    3.  If you die, count = 1.
    4.  **When the count reaches 0, the object deletes itself.**
* **Use case:** ROS2 Messages. Many nodes might want to read the same camera image.

---

## 2. Why do we use it?
1.  **Safety (No Leaks):** You never have to write `delete`. The system cleans up after itself automatically.
2.  **Dangling Pointer Prevention:** If a `shared_ptr` is still holding an object, that object cannot be destroyed. This prevents the crash where you try to access dead memory.
3.  **ROS2 Standard:** ROS2 is built almost entirely on `std::shared_ptr`. If you want to use the framework, you must speak this language.

---

## 3. Syntax & Rules
We use the `std` library functions to create them (requires `#include <memory>`).

### A. Creating a Unique Pointer
```cpp
// Create a unique pointer to an integer with value 10
std::unique_ptr<int> p1 = std::make_unique<int>(10);

```

### B. Creating a Shared Pointer

```cpp
// Create a shared pointer to a Robot object
std::shared_ptr<Robot> p2 = std::make_shared<Robot>();

```

---

## 4. The Trap: "The Cyclic Dependency" ⚠️

This is an advanced bug but good to know.

* **Scenario:** Object A has a `shared_ptr` to B. Object B has a `shared_ptr` to A.
* **Result:** A holds B, B holds A. Neither ever reaches "Count 0". They never die. This is a memory leak.
* **Fix:** Use `std::weak_ptr` (a pointer that watches but doesn't keep the object alive) for one of the links.

---

## 5. Code Example

```cpp
#include <iostream>
#include <memory> // REQUIRED

class Camera {
public:
    Camera() { std::cout << "  [Camera] Powering ON (Constructor)\n"; }
    ~Camera() { std::cout << "  [Camera] Powering OFF (Destructor)\n"; }
    void snap() { std::cout << "  [Camera] Click!\n"; }
};

int main() {
    std::cout << "--- Start of Main ---\n";

    // 1. Shared Pointer Scope
    {
        std::cout << "--- Entering Scope ---\n";
        
        // We create a Shared Pointer to a Camera
        // The Constructor runs immediately
        std::shared_ptr<Camera> cam_ptr = std::make_shared<Camera>();
        
        // Use Count is 1
        std::cout << "Pointer Use Count: " << cam_ptr.use_count() << "\n";

        {
             // 2. Another pointer shares the SAME object
             std::shared_ptr<Camera> second_ptr = cam_ptr;
             std::cout << "Pointer Use Count: " << cam_ptr.use_count() << " (Shared!)\n";
             
             second_ptr->snap();
        } 
        // 'second_ptr' dies here. Count drops back to 1.
        std::cout << "Pointer Use Count: " << cam_ptr.use_count() << " (Back to 1)\n";
        
        std::cout << "--- Exiting Scope ---\n";
    } 
    // 'cam_ptr' dies here. Count drops to 0. 
    // The Destructor runs AUTOMATICALLY now.

    std::cout << "--- End of Main ---\n";
    return 0;
}

```

---

## 6. ROS2 Context: "The Node Pointer"

In ROS2, when you initialize a Node, you almost always create it as a Shared Pointer.

### The Pattern:

```cpp
// Traditional C++
// MyNode node;
// rclcpp::spin(&node); // Requires pointer address

// ROS2 Modern C++
// We create a Shared Pointer to the node.
// If the executor crashes or restarts, the node is safe.
auto node = std::make_shared<MyNode>();
rclcpp::spin(node);

```

Also, when you receive a message in a callback:
`void callback(const std_msgs::msg::String::SharedPtr msg)`
*ROS2 gives you a Smart Pointer to the message. You don't own it; you share it.*

---

## 7. Task: "The Shared Sensor" ✅

**Scenario:**
You have a Lidar data object. Two different algorithms (Obstacle Detection and SLAM) need to use this data at the same time.

**Requirements:**

1. Create a class `LidarData`.
* **Constructor:** Print "Data Allocated".
* **Destructor:** Print "Data Freed".


2. **In Main:**
* Create a `shared_ptr` named `main_ptr` to a `LidarData` object.
* Print the `use_count()` (Should be 1).
* Create a new scope `{ ... }`.
* Inside, create another pointer `algo_ptr` equal to `main_ptr`.
* Print `use_count()` (Should be 2).
* Close the scope.
* Print `use_count()` (Should be 1).
* Reset `main_ptr` (`main_ptr.reset()`).



**Observation:**
Does the "Data Freed" message appear immediately after reset?

*Goal: This proves you understand how Shared Pointers keep objects alive exactly as long as they are needed, and no longer.*

```
