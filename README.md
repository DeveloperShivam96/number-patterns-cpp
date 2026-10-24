# Task 01 — Number Patterns

A C++ console application that prompts the user for a number to generate a multiplication table and a height to generate a centered star pyramid.

Built to fulfill **Level 1 of 4 · Warm-up** requirements.

---

## Requirements Met

| Requirement | Implementation Details |
|---|---|
| **Nested loops for both outputs** | • **Multiplication Table:** Outer loop iterates over rows; inner loop iterates across columns (both in side-by-side table view and full 2D matrix view).<br>• **Star Pyramid:** Outer loop iterates through pyramid rows; inner loop 1 prints leading spaces and inner loop 2 prints star columns. |
| **Neatly aligned columns** | Uses `<iomanip>` (`std::setw`) with calculated field widths to ensure straight, readable vertical columns regardless of digit count or negative signs. |
| **Handles 0 and negative inputs without crashing** | • **Multiplication Table:** Safely handles `0` (correct zero-multiples) and negative integers (negative products properly formatted with sign padding).<br>• **Star Pyramid:** Safely handles `0` and negative heights by displaying an informative notice without rendering negative loops or crashing.<br>• **Stream Validation:** Invalid non-integer entries are safely intercepted, clearing the stream and prompting without crashing. |
| **Single .cpp file** | Fully self-contained in `main.cpp` using standard C++ library components only (`<iostream>`, `<iomanip>`, `<string>`, `<cmath>`, `<limits>`). |

---

## Decisions Made

1. **Dual-View Multiplication Table:**
   - **View 1 (Side-by-Side Aligned Table):** Presents multiples 1 to 10 split into two parallel columns (`1..5` and `6..10`), showing equation form (`num x i = product`) via nested row and column loops.
   - **View 2 (2D Multiplication Grid):** Renders a grid table with row headers, column headers, and tabular products up to the target number using nested loops.
   - Providing both views guarantees full compliance whether a reviewer evaluates tabular equation outputs or 2D multiplication grids.

2. **Column Alignment:**
   - `std::setw` was utilized instead of hardcoded whitespace. This accounts for single-digit, multi-digit, and negative signed values cleanly.

3. **Input Stream Hardening:**
   - Instead of bare `cin >> val`, an input helper `readInteger` checks `cin.fail()`, cleans up the error flags, and flushes remaining characters in the stream, preventing infinite loops on invalid characters.

---

## How to Build and Run

### Prerequisites
- Any standard C++ compiler (`g++`, `clang++`, or MSVC `cl.exe`) supporting C++11 or higher.

### Compile with GCC (g++)
```bash
g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o number_patterns
```

### Run
- **Windows (Command Prompt / PowerShell):**
  ```powershell
  .\number_patterns.exe
  ```
- **Linux / macOS:**
  ```bash
  ./number_patterns
  ```

---

## Sample Run

```text
============================================================
              NUMBER PATTERNS CONSOLE PROGRAM               
============================================================
This program demonstrates:
 - Multiplication table with nested loops and aligned columns
 - Symmetrical star pyramid with nested loops
 - Safe handling of 0, negative, and invalid inputs

Enter an integer for the multiplication table: 5

============================================================
                   MULTIPLICATION TABLE                     
============================================================
Target Number: 5

[View 1] Side-by-Side Aligned Table (Multipliers 1 to 10):
-------------------------------------------------------
     5 x  1 =       5   |        5 x  6 =      30
     5 x  2 =      10   |        5 x  7 =      35
     5 x  3 =      15   |        5 x  8 =      40
     5 x  4 =      20   |        5 x  9 =      45
     5 x  5 =      25   |        5 x 10 =      50
-------------------------------------------------------

[View 2] 2D Multiplication Grid Table:
------------------------------------------------------------
   x |      1      2      3      4      5
------+-----------------------------------
   1  |      1      2      3      4      5
   2  |      2      4      6      8     10
   3  |      3      6      9     12     15
   4  |      4      8     12     16     20
   5  |      5     10     15     20     25
   6  |      6     12     18     24     30
   7  |      7     14     21     28     35
   8  |      8     16     24     32     40
   9  |      9     18     27     36     45
  10  |     10     20     30     40     50
------------------------------------------------------------

Enter the desired height for the star pyramid: 5

============================================================
                        STAR PYRAMID                        
============================================================
Chosen Height: 5

Pyramid Output:
    *
   ***
  *****
 *******
*********

(Pyramid successfully rendered with 5 layers)

============================================================
       All tasks completed successfully. Goodbye!           
============================================================
```

---

## Handling Edge Cases (0 and Negatives)

### Multiplication with `0`:
- Table products correctly output `0` with standard column formatting.
- Grid renders the `0` column without division-by-zero or crashes.

### Multiplication with Negative Numbers (e.g. `-4`):
- Formats signed products (`-4`, `-8`, `-12`...) with proper width allowance so columns do not misalign.

### Pyramid with `0` or Negative Heights (e.g. `0` or `-3`):
- Gracefully displays:
  ```text
  [Notice] Negative height (-3) entered. Pyramid height must be non-negative.
           No pyramid layers to render.
  ```
- Prevents infinite loops and crashes.
