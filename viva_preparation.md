# Examination Management System in C - Complete Viva Preparation Guide

---

## 1. Project Summary

- **Project Name:** Examination Management System
- **Language:** C (Standard C99 / C11)
- **Programming Level:** Beginner-Friendly, Single-File (`main.c`)
- **Data Storage:** In-Memory (RAM) using an array of `struct` (`MAX = 50`)
- **No Complex Dependencies:** No database (SQL), no file handling, no pointer arithmetic, no external libraries.
- **5 Academic Subjects Included:**
  1. Discrete Mathematics (`dms`)
  2. RDBMS (`rdbms`)
  3. Programming in C (`c_prog`)
  4. Web Technologies (`web`)
  5. Data Visualization (`data_vis`)

---

## 2. Structure & Member Variables Explanation

```c
struct Student {
    int roll;
    char name[50];
    float dms;
    float rdbms;
    float c_prog;
    float web;
    float data_vis;
    float tot;
    float per;
    char grd[5];
    char res[10];
};
```

| Member Variable | Data Type      | Purpose & Viva Explanation                                                              |
| :-------------- | :------------- | :-------------------------------------------------------------------------------------- |
| `roll`        | `int`        | Stores the unique roll number of the student. Checked to be positive and non-duplicate. |
| `name[50]`    | `char array` | Stores the full name of the student (up to 49 characters + `\0` null terminator).     |
| `dms`         | `float`      | Marks in **Discrete Mathematics** (range $0.0$ to $100.0$).                   |
| `rdbms`       | `float`      | Marks in **Relational Database Management Systems** ($0.0$ to $100.0$).       |
| `c_prog`      | `float`      | Marks in **Programming in C** ($0.0$ to $100.0$).                             |
| `web`         | `float`      | Marks in **Web Technologies** ($0.0$ to $100.0$).                             |
| `data_vis`    | `float`      | Marks in **Data Visualization** ($0.0$ to $100.0$).                           |
| `tot`         | `float`      | Total marks obtained across all 5 subjects (out of $500.00$).                         |
| `per`         | `float`      | Percentage calculated as $(\text{tot} / 500.0) \times 100$.                           |
| `grd[5]`      | `char array` | Stores grade string: `"A+"`, `"A"`, `"B"`, `"C"`, `"D"`, or `"F"`.          |
| `res[10]`     | `char array` | Stores final examination status: `"PASS"` or `"FAIL"`.                              |

### Important Viva Points on the Structure:

- **Why `float` instead of `int` for marks?**To allow fractional marks (e.g., $85.5$) and prevent integer truncation when calculating percentage.
- **Why character arrays for `grd` and `res`?**
  In C, `"A+"` and `"PASS"` are multi-character strings that require string storage with space for the null character `\0`.

---

## 3. Global Variables

```c
#define MAX 50
struct Student s[MAX];
int n = 0;
```

| Identifier | Type                        | Role                                                             |
| :--------- | :-------------------------- | :--------------------------------------------------------------- |
| `MAX`    | Preprocessor Macro (`50`) | Maximum student storage capacity in memory.                      |
| `s[MAX]` | Array of `struct Student` | In-memory database holding up to 50 student records.             |
| `n`      | `int`                     | Tracks the active count of registered students. Starts at `0`. |

---

## 4. Functions Explanation (Line-by-Line Logic)

### 1. `void flush()`

- **Code:**
  ```c
  void flush() {
      int c;
      while ((c = getchar()) != '\n' && c != EOF);
  }
  ```
- **What it does:** Reads and discards any remaining characters in the `stdin` buffer up to the newline.
- **Viva Answer:** `scanf("%d", ...)` only reads numbers and leaves the user's `Enter` (`\n`) key in the input buffer. Without `flush()`, the following `fgets()` will read that leftover `\n` and skip user input.

---

### 2. `void calc(int i)`

- **What it does:** Computes academic results for the student at index `i`.
- **Key Formulas:**
  - $\text{Total: } s[i].\text{tot} = dms + rdbms + c\_prog + web + data\_vis$
  - $\text{Percentage: } s[i].\text{per} = (s[i].\text{tot} / 500.0f) \times 100.0f$
- **Grade Logic (Percentage Thresholds):**
  - $\ge 90\% \implies \text{A+}$
  - $\ge 80\% \implies \text{A}$
  - $\ge 70\% \implies \text{B}$
  - $\ge 60\% \implies \text{C}$
  - $\ge 50\% \implies \text{D}$
  - $< 50\% \implies \text{F}$
- **Passing Condition:**
  `s[i].dms >= 35 && s[i].rdbms >= 35 && s[i].c_prog >= 35 && s[i].web >= 35 && s[i].data_vis >= 35`
  If any single subject mark is $< 35$, the result is `"FAIL"` regardless of the overall percentage.

---

### 3. `void add()`

- **What it does:** Handles input for a new student record and appends it to `s[n]`.
- **Validations Implemented:**
  1. **Capacity Check:** If `n >= MAX`, rejects input and alerts memory is full.
  2. **Positive Roll Number:** Rejects values $\le 0$.
  3. **Duplicate Roll Check:** Loops through `0` to `n-1` to ensure unique roll numbers.
  4. **Trailing Newline Removal:** Uses `s[n].name[strcspn(s[n].name, "\n")] = 0;` to clean string input from `fgets()`.
  5. **Marks Range Validation:** Loops until each subject's mark is strictly between $0.0$ and $100.0$.
  6. **Auto Calculation:** Automatically calls `calc(n)` and increments `n++`.

---

### 4. `void show()`

- **What it does:** Displays all registered students in an aligned tabular overview.
- **Format Specifiers Used:**
  - `%-8d`: Left-aligned 8-character integer (Roll).
  - `%-20s`: Left-aligned 20-character string (Name).
  - `%-10.2f`: Float with 2 decimal places (Total).
  - `%-11.2f%%`: Percentage with escaped literal `%` sign.

---

### 5. `void find()`

- **What it does:** Searches for a student by roll number.
- **Algorithm:** **Linear Search** ($O(n)$). Compares each student's `roll` with the target `r`.
- **Handling Not Found:** Uses flag `found = 0`. If loop finishes without match, outputs `"Student with Roll Number X not found."`

---

### 6. `void card()`

- **What it does:** Generates a detailed individual marksheet/report card for a student showing all 5 subject scores, total marks, percentage, grade, and pass/fail result enclosed in `***` borders.

---

### 7. `void top()`

- **What it does:** Identifies and displays the student with the highest total marks.
- **Tie Handling (Viva Critical):**
  1. Finds `max = s[0].tot` by comparing all students.
  2. Counts how many students have `tot == max` (`topCount`).
  3. If `topCount > 1`, prints a tie notice.
  4. Displays every student sharing the highest marks.

---

### 8. `int main()`

- **What it does:** Driver function containing an infinite `while(1)` loop and a `switch-case` menu (Options 1–6). Exits cleanly returning `0` when Option 6 is selected.

---

## 5. Other Important Language Properties & Concepts

### 1. `#define _CRT_SECURE_NO_WARNINGS`

- Visual Studio flags standard C functions (`scanf`, `strcpy`) as unsafe. This preprocessor directive disables deprecation warnings and lets the standard C code compile cleanly.

### 2. `strcspn(str, "\n")`

- `fgets()` captures the `Enter` key as `\n` at the end of the string.
- `strcspn()` finds the index where `\n` occurs, and we replace it with `0` (null terminator `\0`) to remove the newline.

### 3. Floating-Point Literal `500.0f`

- In C, `500` is an integer. Dividing a float by an integer works, but dividing two integers does integer truncation. Writing `500.0f` explicitly marks it as single-precision float.

---

## 6. Top 12 Viva Questions & Answers

### Q1: Why did you use an array of structures instead of separate arrays?

> **Answer:** An array of structures groups related attributes of a student (`roll`, `name`, `marks`, `grade`) into a single entity. Separate arrays (`roll[50]`, `name[50][50]`, `m1[50]`) would lead to loose data coupling and harder maintenance.

### Q2: What is the scope of variable `n`?

> **Answer:** Global scope (file scope). It is defined outside all functions and can be read and modified by all functions in the file.

### Q3: What is the difference between `scanf("%s", ...)` and `fgets()`?

> **Answer:** `scanf("%s")` stops reading at space characters, so it cannot read a full name like `"Hardik Sharma"`. `fgets()` reads the full line including spaces.

### Q4: What is the time complexity of searching in this program?

> **Answer:** $O(n)$ where $n$ is the number of stored students. It uses linear search.

### Q5: What happens if a student scores 95% overall but 30 in one subject?

> **Answer:** Their grade will be `A+`, but their result will be `FAIL` because the system strictly checks `mark >= 35` for all 5 subjects.

### Q6: What happens when the program is closed?

> **Answer:** The data is lost because records are stored in RAM (volatile memory). Permanent storage would require file handling (`fopen`, `fwrite`) or a database.

### Q7: Why use `while(1)` in the menu and input validation?

> **Answer:** `while(1)` creates an intentional infinite loop. In input validation, it keeps prompting the user until valid data is entered (exiting with `break`). In the menu, it keeps the program running until the user picks Exit (Option 6).

### Q8: What is `strcpy()` and why can't we write `s[i].grd = "A+"`?

> **Answer:** In C, string literals cannot be assigned directly to an array after declaration. `strcpy()` from `<string.h>` copies the characters along with the null terminator `\0` into the destination array.

### Q9: How do you handle multiple class toppers?

> **Answer:** The program scans the array to determine the highest score (`max`), counts the students with that score, and prints details of all students having `tot == max`.

### Q10: How does the program prevent adding more than 50 students?

> **Answer:** In `add()`, it checks `if (n >= MAX)`. If true, it prints an error message and uses `return;` to exit the function without overflowing the array.

### Q11: Why is `clearBuffer()` / `flush()` called after every `scanf()`?

> **Answer:** `scanf()` leaves the newline character `\n` in the input buffer. `flush()` consumes that newline so that subsequent calls to `fgets()` or `scanf()` work properly.

### Q12: How would you compile and run this project in terminal?

> **Answer:**
>
> - In Command Prompt (cmd): `gcc main.c -o exam_system.exe` followed by `exam_system.exe`
> - In PowerShell: `gcc main.c -o exam_system.exe` followed by `.\exam_system.exe`
