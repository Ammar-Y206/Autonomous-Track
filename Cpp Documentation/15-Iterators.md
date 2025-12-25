
# Concept 15: Iterators (Navigation & Modification)

## 1. Deep Explanation (The Logic)
An **Iterator** is a specialized object that acts like a "Moving Finger" pointing to an element inside a container.

* **Think of a `std::vector` as a row of houses.**
* **An Iterator is YOU standing in front of one specific house.**



### Key Positions:
1.  **`begin()`:** Returns an iterator pointing to the **First** element.
2.  **`end()`:** Returns an iterator pointing to the **Theoretical Slot AFTER the last element**.
    * *Note:* It does **not** point to the last item; it points to the "Finish Line". If you try to read data at `end()`, the program crashes.

**The Logic:** You start at `begin()`. You keep stepping forward (`it++`) until you hit `end()`. At any point, you can look at the value (`*it`).

---

## 2. Why do we use it?
1.  **Navigating Maps:** `std::map` does not have index numbers like 0, 1, 2. You cannot say `map[0]`. You **must** use an iterator to walk through it.
2.  **Modifying the List:** If you want to erase an item while looping through a list (e.g., "Remove all points that are too far away"), you cannot use a normal `for` loop efficiently. You need iterators.

---

## 3. Syntax & Rules

### A. Creating an Iterator
Instead of typing the long type (`std::vector<int>::iterator`), we almost always use `auto`.

```cpp
std::vector<int> nums = {10, 20, 30};
auto it = nums.begin(); // Points to 10

```

### B. Accessing Data

* **`*it`**: Gets the value (like a pointer).
* **`it->first`**: (For Maps) Gets the Key.
* **`it->second`**: (For Maps) Gets the Value.

---

## 4. The Trap: "Iterator Invalidation" ⚠️

This is a classic crash.

* **Scenario:** You are iterating through a vector. You find a bad item and `erase()` it.
* **The Crash:** When you erase an item, the vector shifts all memory around to fill the gap. Your iterator `it` is now pointing to a memory address that might not exist or has moved. It is **"Invalid"**.
* **The Fix:** The `erase()` function returns a **new, valid iterator** pointing to the next item. You must catch it:
* `it = vec.erase(it);`



---

## 5. Code Example

```cpp
#include <iostream>
#include <vector>
#include <map>

int main() {
    // --- 1. Vector Iterator ---
    std::vector<int> path = {10, 20, 30, 40};
    
    std::cout << "Path: ";
    // "Start at begin; Stop when we hit end; Step forward"
    for (auto it = path.begin(); it != path.end(); it++) {
        // We use *it to see the value
        std::cout << *it << " "; 
        
        // Example: Modifying the value
        if (*it == 20) {
            *it = 99; 
        }
    }
    std::cout << "\nModified Path: " << path[1] << "\n"; // Prints 99

    // --- 2. Map Iterator (The only way to loop a Map) ---
    std::map<std::string, int> robot_ids;
    robot_ids["Drone"] = 101;
    robot_ids["Rover"] = 202;

    std::cout << "\n--- Robot Registry ---\n";
    for (auto it = robot_ids.begin(); it != robot_ids.end(); it++) {
        // For maps, 'it' holds a Pair.
        // it->first is the Name (Key)
        // it->second is the ID (Value)
        std::cout << "Name: " << it->first << " | ID: " << it->second << "\n";
    }

    return 0;
}

```

---

## 6. ROS2 Context: "Point Cloud Filtering"

In advanced robotics, we process **Point Clouds** (millions of points).

Often, we want to remove points that are "NaN" (Not a Number / Errors).
We use standard algorithms like `std::remove_if` which rely entirely on **iterators** to sweep through the cloud efficiently and clean it up.

---

## 7. Task: "The Clean-Up Crew" ✅

**Scenario:**
You have a list of sensor readings. Some are valid (positive numbers), but some are errors (negative numbers). You need to delete the errors.

**Requirements:**

1. Create a `std::vector<int>` with values: `{10, -5, 20, -1, 30}`.
2. **The Logic Puzzle:**
* Write a `for` loop using an iterator `it`.
* Check if `(*it < 0)`.
* **Action:** If it is negative, use `it = vec.erase(it);`. (This deletes it and updates the iterator).
* **Else:** If it is positive, just do `it++;`. (Only step forward if you didn't delete!).



**Output:**
Print the final vector.

**Observation:**
It should print only `{10, 20, 30}`.
*If your code crashes or skips a number, it means you mishandled the erase logic (e.g., doing `it++` after erasing).*


