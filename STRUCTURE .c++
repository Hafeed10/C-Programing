#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student details
struct Student
{
    int enrolmentNumber;
    char name[50];
    float marks;
    int rank;
};

// Function to sort students based on marks (descending order)
void sortStudentsByMarks(struct Student students[], int n)
{
    struct Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].marks < students[j + 1].marks)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to assign ranks to students
void assignRanks(struct Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && students[i].marks == students[i - 1].marks)
        {
            students[i].rank = students[i - 1].rank; // Same rank for equal marks
        }
        else
        {
            students[i].rank = i + 1; // Assign rank based on position
        }
    }
}

// Function to sort students by rank (ascending order)
void sortStudentsByRank(struct Student students[], int n)
{
    struct Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].rank > students[j + 1].rank)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to display the students' details
void displayStudents(struct Student students[], int n)
{
    printf("\nEnrolment Number\tName\t\tMarks\t\tRank\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t\t%-15s\t%.2f\t\t%d\n",
               students[i].enrolmentNumber, students[i].name, students[i].marks, students[i].rank);
    }
}

int main()
{
    int n;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Input the details of each student
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enrolment Number: ");
        scanf("%d", &students[i].enrolmentNumber);
        printf("Name: ");
        scanf(" %[^\n]%*c", students[i].name); // Read string with spaces
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Sort by marks and assign ranks
    sortStudentsByMarks(students, n);
    assignRanks(students, n);

    // Sort by rank and display students
    sortStudentsByRank(students, n);
    displayStudents(students, n);

    return 0;
}
