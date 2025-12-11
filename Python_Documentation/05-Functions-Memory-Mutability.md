
# Concept 5: Functions, Memory & Mutability

## 1\. Deep Explanation (The Logic & Memory)

In C++, you have to choose between "Pass by Value" (Copy) and "Pass by Reference" (Link).

**In Python, the rule is simple but unique:**
**"Pass by Object Reference" (Call by Assignment).**

This means Python **ALWAYS** passes a "Link" (Reference) to the object. It **NEVER** automatically copies data. However, the *result* depends on whether the object is **Mutable** or **Immutable**.

### A. Immutable Objects (Behave like "Pass by Value")

  * **Types:** `int`, `float`, `str`, `tuple`.
  * **Behavior:** These objects **cannot** be changed.
  * **Scenario:** If you pass an integer `x` to a function and try to change it (`x = 5`), Python creates a **NEW** integer object at a new address and moves the function's local label to it. The original `x` outside remains untouched.

### B. Mutable Objects (Behave like "Pass by Reference")

  * **Types:** `list`, `dict`, `set`, `dataclass` (Objects).
  * **Behavior:** These objects **can** be changed in place.
  * **Scenario:** If you pass a list `my_list` to a function and do `my_list.append(1)`, the function follows the link to the **original** list and adds the number. The original list changes immediately.

-----

## 2\. Why do we use it? (The Engineering View)

1.  **Performance (Implicit):**

      * In ROS2, passing a 5MB image (List/Array) to a function is **Instant**. Python does not copy the 5MB; it just passes the address of the existing list. You don't need special syntax like `&`; it just works.

2.  **Multiple Outputs:**

      * **C++ Way:** Pass variables by Reference (`void func(int &out1, int &out2)`).
      * **Python Way:** Python functions can natively **Return Multiple Values** (as a Tuple). This is cleaner and safer than modifying input variables.

-----

## 3\. Syntax & The `id()` Check 🔍

To understand this, we use `id()`. This function reveals the "Passport Number" (Memory Address) of a variable.

### A. The "Immutable" Proof (Integer)

Behaves like C++ "Pass by Value".

```python
def try_change_number(val):
    print(f"   [Func] Address before change: {id(val)}")
    val = 500  # Creates a NEW object here!
    print(f"   [Func] Address after change:  {id(val)} (Changed!)")

my_number = 10
print(f"1. MAIN Address: {id(my_number)}")
try_change_number(my_number)
print(f"   [Main] Value: {my_number} (Unchanged - Original address still holds 10)")
```

### B. The "Mutable" Proof (List)

Behaves like C++ "Pass by Reference".

```python
def change_list(ref_list):
    print(f"   [Func] Address: {id(ref_list)} (Same as Main!)")
    ref_list.append(999) # Modifies the ORIGINAL object

my_data = [1, 2, 3]
change_list(my_data)
print(f"   [Main] List: {my_data} (CHANGED!)")
```

-----

## 4\. ROS2 Context: "The Subscriber Callback"

When a ROS2 node receives a message (like `LaserScan`):

1.  **Memory:** Python receives the message object.
2.  **Efficiency:** It passes this object to your callback function by **Reference**. It does *not* copy the sensor data.
3.  **Safety:** Because ROS2 messages in Python are essentially Objects, if you modify `msg.ranges` inside your callback, you are modifying that specific memory object. However, standard practice is to treat inputs as Read-Only unless you are specifically writing a filter.

-----

## 5\. Task: The "Stats Keeper" ✅

**Scenario:**
You need to analyze a list of battery voltages to find the **Minimum** and **Maximum**.

**The Python Difference:**
In C++, you passed `min` and `max` variables *into* the function to be modified.
In Python, because numbers are **Immutable**, we cannot pass them in to be changed. Instead, we use the **Pythonic Multiple Return**.

**Requirements:**

1.  Define `volts = [12.5, 11.8, 13.1, 12.0]`
2.  **The Logic Puzzle:**
      * Create a function `def find_extremes(data_list):`.
      * Inside, find the min and max (you can use manual loops or built-in `min()`/`max()` functions).
      * **Return** both values at once: `return min_val, max_val`
3.  **In Main:**
      * Capture the result: `min_v, max_v = find_extremes(volts)`
      * Print the results.

**Code Solution:**

```python
# 1. Define Data
volts = [12.5, 11.8, 13.1, 12.0]

# 2. Define Function
def find_extremes(data_list):
    # 'data_list' is a Reference to 'volts'. 
    # No copying happens (Fast ⚡).
    
    # Logic to find min/max
    minimum = min(data_list)
    maximum = max(data_list)
    
    # Python can return a "Tuple" (Package of values)
    return minimum, maximum

# 3. Main Execution
# We "Unpack" the tuple into two variables
min_v, max_v = find_extremes(volts)

print(f"List: {volts}")
print(f"Min Voltage: {min_v}")
print(f"Max Voltage: {max_v}")
```
