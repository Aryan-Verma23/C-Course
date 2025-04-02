#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  
 struct Employee {
    int id;
    char name[50];
    char role[10];  
    float salary;
};

int main() {
   struct Employee employees[MAX];
    int n;
    FILE *manager,*employee;

   
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf(" %[^\n]", employees[i].name); 
        printf("Role (Manager/Worker): ");
        scanf("%s", employees[i].role);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

  
    FILE *managerFile = fopen("managers.txt", "w");
    FILE *workerFile = fopen("workers.txt", "w");

    if (managerFile == NULL || workerFile == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (strcasecmp(employees[i].role, "Manager") == 0) {
            fprintf(managerFile, "ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
        } else if (strcasecmp(employees[i].role, "Worker") == 0) {
            fprintf(workerFile, "ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
        }
    }
    fclose(managerFile);
    fclose(workerFile);

    printf("\n written to 'managers.txt' and 'workers.txt'.\n");

    return 0;
}
