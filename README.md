# Examination Management System

The **Examination Management System** is a lightweight, console-based academic management application developed in standard C. It is designed to simplify and automate core examination evaluation tasks for educational institutions, such as recording student information, tracking subject-wise marks, computing performance metrics, and generating reports.

---

## About the Project & Features

This project provides an intuitive, menu-driven command-line interface tailored for managing student examination records in program memory.

---

### 1. Main Navigation Menu
- **What it does:** Serves as the central control dashboard for the user. It prompts with six distinct numerical options to navigate between operations or safely exit the program.

```text
****************************************
     EXAMINATION MANAGEMENT SYSTEM      
****************************************
1. Add Student Details and Marks
2. Display All Students
3. Search Student by Roll Number
4. Generate Individual Result Card
5. Display Class Topper
6. Exit
****************************************
Enter your choice (1-6): 
```

---

### 2. Add Student Details & Marks (Option 1)
- **What it does:** Accepts a unique positive roll number, the student's full name, and marks out of 100 for each of the five subjects.
- **Validation:** 
  - Prevents duplicate or non-positive roll numbers.
  - Enforces marks to strictly lie between `0` and `100`.
  - Automatically calculates total marks, percentage, grade, and pass/fail result upon submission.

```text
--- Add Student ---
Enter Roll Number: 101
Enter Student Name: Hardik Sharma

Enter marks out of 100:
Discrete Mathematics: 88
RDBMS: 92
Programming in C: 95
Web Technologies: 84
Data Visualization: 90
Student added successfully!
```

---

### 3. Display All Students (Option 2)
- **What it does:** Displays an aligned tabular summary of all registered student records in memory, showing their roll number, name, total marks, percentage, assigned grade, and pass/fail status.

```text
----------------------------------------------------------------------
Roll     Name                 Total      Percentage   Grade    Result  
----------------------------------------------------------------------
101      Hardik Sharma        449.00     89.80      % A        PASS    
102      Rohan Verma          325.00     65.00      % C        FAIL    
----------------------------------------------------------------------
Total Students: 2
```

---

### 4. Search Student by Roll Number (Option 3)
- **What it does:** Allows fast lookup of a specific student record using linear search. If found, displays their academic overview; if not found, notifies the user.

```text
Enter Roll Number to search: 101

--- Student Found ---
Roll Number : 101
Name        : Hardik Sharma
Total Marks : 449.00 / 500
Percentage  : 89.80%
Grade       : A
Result      : PASS
```

---

### 5. Generate Individual Result Card (Option 4)
- **What it does:** Generates a formal, marksheet-style report card for the requested student roll number, detailing subject-by-subject scores, total marks out of 500, percentage, letter grade, and final result.
- **Pass/Fail Rule:** Student must score $\ge 35$ in all five subjects to receive a `PASS`. Scoring below 35 in any subject results in a `FAIL`.

```text
Enter Roll Number for Result Card: 101

**************************************************
                STUDENT RESULT CARD               
**************************************************
Roll Number          : 101
Name                 : Hardik Sharma
--------------------------------------------------
Discrete Mathematics : 88.00 / 100
RDBMS                : 92.00 / 100
Programming in C     : 95.00 / 100
Web Technologies     : 84.00 / 100
Data Visualization   : 90.00 / 100
--------------------------------------------------
Total Marks          : 449.00 / 500.00
Percentage           : 89.80%
Grade                : A
Result               : PASS
**************************************************
```

---

### 6. Display Class Topper (Option 5)
- **What it does:** Identifies and displays the student who achieved the highest total marks in the class. If multiple students achieve the same top score, it recognizes the tie and displays all rank 1 holders.

```text
****************************************
              CLASS TOPPER              
****************************************
Roll Number : 101
Name        : Hardik Sharma
Total Marks : 449.00 / 500.00
Percentage  : 89.80%
Grade       : A
Result      : PASS
----------------------------------------
```
