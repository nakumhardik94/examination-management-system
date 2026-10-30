# Examination Management System in C

A beginner-friendly, menu-driven Examination Management System written in standard C (C99/C11). Designed for college viva and lab coursework demonstration with simple in-memory storage, input validation, and automatic result processing.

---

## Features

1. **Student Details**: Store Roll Number and Name.
2. **Subject Marks**: Input marks for 5 core theory subjects with 0–100 validation:
   - Discrete Mathematics
   - Relational Database Management Systems (RDBMS)
   - Programming & Problem-Solving Using C
   - Web Technologies
   - Data Visualization
3. **Total Marks**: Calculates total marks obtained out of 500.
4. **Percentage**: Computes percentage with 2-decimal precision.
5. **Grade Calculation**:
   - `90% - 100%`: A+
   - `80% - 89.99%`: A
   - `70% - 79.99%`: B
   - `60% - 69.99%`: C
   - `50% - 59.99%`: D
   - `Below 50%`: F
6. **Result Generation**:
   - **PASS**: At least 35 marks in all 5 subjects.
   - **FAIL**: Less than 35 marks in any subject.
   - Formatted individual result card.
7. **Topper Identification**: Finds class topper(s) and handles ties gracefully.

---

## Project Structure

```
├── main.c               # Complete source code in a single file (~350 lines)
├── viva_preparation.md  # Detailed viva question & answer guide
├── README.md            # Project documentation
└── .gitignore           # Git ignore for compiled binaries and build artifacts
```

---

## How to Compile & Run

### Using GCC (MinGW / Windows PowerShell):
```powershell
gcc main.c -o exam_system.exe
.\exam_system.exe
```

### Using MSVC (Developer Command Prompt / Visual Studio):
```cmd
cl main.c
exam_system.exe
```

### In Visual Studio IDE:
1. Create an **Empty C/C++ Project** or **Console App**.
2. Add `main.c` to **Source Files**.
3. Press `Ctrl + F5` to compile and run.

---

## License
Open-source under the MIT License.
