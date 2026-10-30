# Examination Management System

The **Examination Management System** is a lightweight, console-based academic management application developed in standard C. It is designed to simplify and automate core examination evaluation tasks for educational institutions, such as recording student information, tracking subject-wise marks, computing performance metrics, and generating reports.

---

## About the Project

This project provides an intuitive, menu-driven interface tailored for managing student examination records efficiently within program memory:

- **Student Record Management**: Allows entry and tracking of student details, including unique roll numbers and student names.
- **Academic Course Evaluation**: Evaluates scores across five core theoretical subjects:
  1. Discrete Mathematics
  2. Relational Database Management Systems (RDBMS)
  3. Programming & Problem-Solving Using C
  4. Web Technologies
  5. Data Visualization
- **Input Validation**: Ensures data integrity by verifying that entered roll numbers are positive and unique, and that subject marks strictly fall within the valid range of 0 to 100.
- **Automated Score Calculations**: Automatically computes each student's total marks (out of 500) and calculates the overall percentage.
- **Grading & Pass/Fail Evaluation**: Assigns letter grades (`A+`, `A`, `B`, `C`, `D`, `F`) using standard percentage brackets and determines final result status based on a clear passing rule (a minimum score of 35 in every subject).
- **Result & Performance Reports**: Generates detailed individual marksheets, class-wide summary tables, and identifies class topper(s) while accounting for tie scores.
