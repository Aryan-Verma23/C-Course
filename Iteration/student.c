#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "Student.txt"

typedef struct {
    int rollNo;
    char name[50];
    float marks;
} Student;

void addStudent() {
    FILE *file = fopen(FILE_NAME, "ab"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    getchar(); 
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; 
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
    printf("Student record added successfully!\n");
}

void displayStudents() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    Student s;
    printf("\nStudent Records:\n");
    printf("------------------------------------------------\n");
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", s.rollNo, s.name, s.marks);
    }
    printf("------------------------------------------------\n");

    fclose(file);
}

void editStudent() {
    FILE *file = fopen(FILE_NAME, "rb+"); 
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    int rollNo, found = 0;
    Student s;
    printf("Enter Roll Number to Edit: ");
    scanf("%d", &rollNo);

    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNo == rollNo) {
            found = 1;
            printf("Enter New Name: ");
            getchar(); 
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0;
            printf("Enter New Marks: ");
            scanf("%f", &s.marks);

            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, file);
            printf("Record Updated Successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Record not found!\n");

    fclose(file);
}

void appendStudent() {
    addStudent(); 
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Edit Student Record\n");
        printf("4. Append Student Record\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: editStudent(); break;
            case 4: appendStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
