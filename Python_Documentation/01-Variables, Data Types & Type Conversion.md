
# Concept 1: Variables, Data Types & Type Conversion

## 1\. Deep Explanation (The Logic)

In Python, a variable is essentially a **label** or a **name** attached to a piece of data in memory.

Python is **Dynamically Typed**. This means:

  * You **do not** need to declare a specific type (like "integer" or "text") when creating a variable.
  * Python figures out the type automatically based on the value you assign.
  * You can change the type of data a variable holds at any time (though in large projects, we usually try to keep them consistent).

Think of a variable like a sticky note you place on a box. You can move that sticky note to a different box whenever you want.

**Common Data Types:**

  * **`int` (Integer):** Stores whole numbers. Python integers can grow to become very large automatically.
  * **`float` (Floating Point):** Stores decimal numbers. This is Python's standard for precision math.
  * **`bool` (Boolean):** Stores only `True` or `False`.
  * **`str` (String):** Stores text characters.

-----

## 2\. The Logic: "Decimal vs. Floor Math"

In strict programming environments, dividing two integers often results in an integer (dropping the decimal). **Python behaves differently.**

Python has two types of division operators:

1.  **Standard Division (`/`):** This **always** results in a `float` (decimal), even if you divide two whole numbers.

      * `5 / 2` $\rightarrow$ `2.5`
      * **Benefit:** You rarely lose precision by accident in Python.

2.  **Floor Division (`//`):** This forces the result to be an integer by rounding **down** (discarding the decimal).

      * `5 // 2` $\rightarrow$ `2`
      * **Usage:** Useful when you need whole numbers only (e.g., counting items, pixel coordinates).

-----

## 3\. The Tool: Explicit Type Conversion

Even though Python handles division safely, there are times you need to manually force a variable to be a specific type. This is called **Explicit Type Conversion**.

**Why do this?**

1.  **Input Handling:** Data from a user or a text file often comes in as a `str` (text), and you must convert it to a number to do math.
2.  **Strict Contracts:** Some external libraries (like ROS2) require you to send data as a specific type (e.g., ensuring a number is a `float` before sending it).

<!-- end list -->

  * **Syntax:** `new_type(variable)`
  * **Examples:**
      * `float(5)` becomes `5.0`
      * `int(5.9)` becomes `5` (truncates the decimal)
      * `str(10)` becomes `"10"`

-----

## 4\. Code Example

```python
# --- 1. Defining Variables (Python infers the type) ---
encoder_ticks = 150       # Python sees a whole number -> int
max_ticks = 1000          # Python sees a whole number -> int
motor_id = "M1"           # Python sees quotes -> str

# --- 2. Standard Division (Safe) ---
# Even though both variables are ints, '/' creates a float automatically.
# 150 / 1000 = 0.15
standard_result = encoder_ticks / max_ticks

# --- 3. Floor Division (Truncating) ---
# If you used '//', you would lose the data.
# 150 // 1000 = 0
floor_result = encoder_ticks // max_ticks

# --- 4. Explicit Conversion (Casting) ---
# We can manually force 'encoder_ticks' to be a float.
# This is often done to be explicit about your intentions.
explicit_result = float(encoder_ticks) / max_ticks

# Output
print(f"Motor: {motor_id}")
print(f"Standard Division (/): {standard_result}")  # Result: 0.15
print(f"Floor Division (//):   {floor_result}")     # Result: 0
print(f"Explicit Conversion:   {explicit_result}")  # Result: 0.15
```

-----

## 5\. ROS2 Context: "The Data Contract"

In ROS2, independent nodes (like a Camera Node and a Motor Node) talk to each other. They do this by agreeing on a strict **Contract** called a **Message (.msg)**.

Even though Python is flexible, ROS2 is strict.

1.  **The Contract:** If the message file says the speed is a `float64`, your Python code must provide a `float`.
2.  **The Bridge:** Your hardware might give you `int` data (raw sensor ticks), but the ROS2 message requires `float64` (physical speed).
3.  **Your Job:** You act as the bridge. You take the `int` from the hardware and ensure it is sent as a `float` to the ROS2 system.

**Common Mapping:**

  * Python `float` $\leftrightarrow$ ROS2 `float64` (Standard for Physics).
  * Python `int` $\leftrightarrow$ ROS2 `int32`.

-----

## 6\. Task: The "Distance Sensor" Logic ✅

**Scenario:**
You have an ultrasonic sensor. It measures the time (in microseconds) it takes for sound to bounce back. You need to convert this time into a distance in Meters.

**Given Data:**

```python
time_microseconds = 5882
```

**Conversion Formula:** $Distance (cm) = Time / 58$

**Requirements:**

1.  Define the variable `time_microseconds`.
2.  **The Logic Puzzle:**
      * Calculate the distance in centimeters.
      * Convert that result to meters (divide by 100).
      * Store the final result in a variable named `distance_meters`.
3.  **Constraint:** Use the function `float()` on the `time_microseconds` variable during the calculation to be explicit about the type conversion.
4.  Print the result.

*(The correct answer is approx 1.014 meters).*
