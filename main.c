#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student
{
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

struct Student s[MAX];
int n = 0;

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void calc(int i)
{
    s[i].tot = s[i].dms + s[i].rdbms + s[i].c_prog + s[i].web + s[i].data_vis;
    s[i].per = (s[i].tot / 500.0f) * 100.0f;

    if (s[i].per >= 90)
        strcpy(s[i].grd, "A+");
    else if (s[i].per >= 80)
        strcpy(s[i].grd, "A");
    else if (s[i].per >= 70)
        strcpy(s[i].grd, "B");
    else if (s[i].per >= 60)
        strcpy(s[i].grd, "C");
    else if (s[i].per >= 50)
        strcpy(s[i].grd, "D");
    else
        strcpy(s[i].grd, "F");

    if (s[i].dms >= 35 && s[i].rdbms >= 35 && s[i].c_prog >= 35 && s[i].web >= 35 && s[i].data_vis >= 35)
    {
        strcpy(s[i].res, "PASS");
    }
    else
    {
        strcpy(s[i].res, "FAIL");
    }
}

void add()
{
    int r, i, found;

    if (n >= MAX)
    {
        printf("\nStudent list is full!\n");
        return;
    }

    printf("\n--- Add Student ---\n");

    while (1)
    {
        printf("Enter Roll Number: ");
        if (scanf("%d", &r) != 1)
        {
            printf("Invalid! Enter numbers only.\n");
            flush();
            continue;
        }
        flush();

        if (r <= 0)
        {
            printf("Roll number must be positive.\n");
            continue;
        }

        found = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i].roll == r)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            printf("Roll number already exists! Try again.\n");
        }
        else
        {
            s[n].roll = r;
            break;
        }
    }

    printf("Enter Student Name: ");
    fgets(s[n].name, 50, stdin);
    s[n].name[strcspn(s[n].name, "\n")] = 0;

    printf("\nEnter marks out of 100:\n");

    while (1)
    {
        printf("Discrete Mathematics: ");
        if (scanf("%f", &s[n].dms) != 1)
        {
            printf("Enter numbers only.\n");
            flush();
            continue;
        }
        flush();
        if (s[n].dms >= 0 && s[n].dms <= 100)
            break;
        printf("Marks must be 0 to 100.\n");
    }

    while (1)
    {
        printf("RDBMS: ");
        if (scanf("%f", &s[n].rdbms) != 1)
        {
            printf("Enter numbers only.\n");
            flush();
            continue;
        }
        flush();
        if (s[n].rdbms >= 0 && s[n].rdbms <= 100)
            break;
        printf("Marks must be 0 to 100.\n");
    }

    while (1)
    {
        printf("Programming in C: ");
        if (scanf("%f", &s[n].c_prog) != 1)
        {
            printf("Enter numbers only.\n");
            flush();
            continue;
        }
        flush();
        if (s[n].c_prog >= 0 && s[n].c_prog <= 100)
            break;
        printf("Marks must be 0 to 100.\n");
    }

    while (1)
    {
        printf("Web Technologies: ");
        if (scanf("%f", &s[n].web) != 1)
        {
            printf("Enter numbers only.\n");
            flush();
            continue;
        }
        flush();
        if (s[n].web >= 0 && s[n].web <= 100)
            break;
        printf("Marks must be 0 to 100.\n");
    }

    while (1)
    {
        printf("Data Visualization: ");
        if (scanf("%f", &s[n].data_vis) != 1)
        {
            printf("Enter numbers only.\n");
            flush();
            continue;
        }
        flush();
        if (s[n].data_vis >= 0 && s[n].data_vis <= 100)
            break;
        printf("Marks must be 0 to 100.\n");
    }

    calc(n);
    n++;
    printf("Student added successfully!\n");
}

void show()
{
    int i;

    if (n == 0)
    {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n----------------------------------------------------------------------\n");
    printf("%-8s %-20s %-10s %-12s %-8s %-8s\n", "Roll", "Name", "Total", "Percentage", "Grade", "Result");
    printf("----------------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%-8d %-20s %-10.2f %-11.2f%% %-8s %-8s\n",
               s[i].roll, s[i].name, s[i].tot, s[i].per, s[i].grd, s[i].res);
    }
    printf("----------------------------------------------------------------------\n");
    printf("Total Students: %d\n", n);
}

void find()
{
    int r, i, found = 0;

    if (n == 0)
    {
        printf("\nNo student records to search.\n");
        return;
    }

    printf("\nEnter Roll Number to search: ");
    if (scanf("%d", &r) != 1)
    {
        printf("Invalid input! Enter numbers only.\n");
        flush();
        return;
    }
    flush();

    for (i = 0; i < n; i++)
    {
        if (s[i].roll == r)
        {
            printf("\n--- Student Found ---\n");
            printf("Roll Number : %d\n", s[i].roll);
            printf("Name        : %s\n", s[i].name);
            printf("Total Marks : %.2f / 500\n", s[i].tot);
            printf("Percentage  : %.2f%%\n", s[i].per);
            printf("Grade       : %s\n", s[i].grd);
            printf("Result      : %s\n", s[i].res);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Student with Roll Number %d not found.\n", r);
    }
}

void card()
{
    int r, i, found = 0;

    if (n == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\nEnter Roll Number for Result Card: ");
    if (scanf("%d", &r) != 1)
    {
        printf("Invalid input! Enter numbers only.\n");
        flush();
        return;
    }
    flush();

    for (i = 0; i < n; i++)
    {
        if (s[i].roll == r)
        {
            printf("\n**************************************************\n");
            printf("                STUDENT RESULT CARD               \n");
            printf("**************************************************\n");
            printf("Roll Number          : %d\n", s[i].roll);
            printf("Name                 : %s\n", s[i].name);
            printf("--------------------------------------------------\n");
            printf("Discrete Mathematics : %.2f / 100\n", s[i].dms);
            printf("RDBMS                : %.2f / 100\n", s[i].rdbms);
            printf("Programming in C     : %.2f / 100\n", s[i].c_prog);
            printf("Web Technologies     : %.2f / 100\n", s[i].web);
            printf("Data Visualization   : %.2f / 100\n", s[i].data_vis);
            printf("--------------------------------------------------\n");
            printf("Total Marks          : %.2f / 500.00\n", s[i].tot);
            printf("Percentage           : %.2f%%\n", s[i].per);
            printf("Grade                : %s\n", s[i].grd);
            printf("Result               : %s\n", s[i].res);
            printf("**************************************************\n");
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Student with Roll Number %d not found.\n", r);
    }
}

void top()
{
    float max;
    int i, topCount = 0;

    if (n == 0)
    {
        printf("\nNo student records to determine topper.\n");
        return;
    }

    max = s[0].tot;
    for (i = 1; i < n; i++)
    {
        if (s[i].tot > max)
        {
            max = s[i].tot;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (s[i].tot == max)
        {
            topCount++;
        }
    }

    printf("\n****************************************\n");
    printf("              CLASS TOPPER              \n");
    printf("****************************************\n");

    if (topCount > 1)
    {
        printf("Note: %d students tied for highest marks!\n\n", topCount);
    }

    for (i = 0; i < n; i++)
    {
        if (s[i].tot == max)
        {
            printf("Roll Number : %d\n", s[i].roll);
            printf("Name        : %s\n", s[i].name);
            printf("Total Marks : %.2f / 500.00\n", s[i].tot);
            printf("Percentage  : %.2f%%\n", s[i].per);
            printf("Grade       : %s\n", s[i].grd);
            printf("Result      : %s\n", s[i].res);
            printf("----------------------------------------\n");
        }
    }
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n****************************************\n");
        printf("     EXAMINATION MANAGEMENT SYSTEM      \n");
        printf("****************************************\n");
        printf("1. Add Student Details and Marks\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Generate Individual Result Card\n");
        printf("5. Display Class Topper\n");
        printf("6. Exit\n");
        printf("****************************************\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &ch) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            flush();
            continue;
        }
        flush();

        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            show();
            break;
        case 3:
            find();
            break;
        case 4:
            card();
            break;
        case 5:
            top();
            break;
        case 6:
            printf("\nExiting program. Thank you!\n");
            return 0;
        default:
            printf("Invalid choice! Choose between 1 and 6.\n");
            break;
        }
    }

    return 0;
}
