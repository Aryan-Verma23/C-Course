#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int grades[MAX_SUBJECTS];
    int numSubjects;
    double average;
} Student;

double calculateAverage(Student *s) {
    int sum = 0;
    for (int i = 0; i < s->numSubjects; i++) {
        sum += s->grades[i];
    }
    return (s->numSubjects > 0) ? ((double)sum / s->numSubjects) : 0;
}

void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStudents(Student students[], int count) {
    printf("\nStudent Details (Sorted by Average Grade):\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Average: %.2f | Status: %s\n", 
               students[i].name, 
               students[i].average, 
               (students[i].average > 60) ? "Pass" : "Fail");
    }
}

int main() {
    int numStudents  = 2 ;
    Student students[MAX_STUDENTS];

    // printf("Enter number of students: ");
    // scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter name for student %d: ", i + 1);
        scanf(" %[^\n]", students[i].name);

        printf("Enter number of subjects: ");
        scanf("%d", &students[i].numSubjects);

        printf("Enter grades for %s:\n", students[i].name);
        for (int j = 0; j < students[i].numSubjects; j++) {
            scanf("%d", &students[i].grades[j]);
        }

        students[i].average = calculateAverage(&students[i]);
    }

    sortStudents(students, numStudents);
    displayStudents(students, numStudents);

    printf("\nTop Student: %s with Average: %.2f\n", 
           students[0].name, students[0].average);

    return 0;
}
