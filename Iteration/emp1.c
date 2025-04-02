#include<stdio.h>
#include<stdlib.h>

#define max 100

struct Employee{
    int id;
    char name[50];
    char role[10];
    int salary;
};

int main(){
    struct Employee employees[max];
    int n;
    FILE *manager,*employee;

    printf("Enter number of Employees\n");
    scanf("%d",&n);

    for(int i = 0;i <= n;i++){
        printf("Enter Details for Employee %d\n",i+1);
        printf("ID: ");
        scanf("%d",&employees[i].id);
        printf("Enter Employee Name:");
        scanf("%[^\n]",&employees[i].name);
        printf("Enter Employee Role:");
        scanf("%s",&employees[i].role);
        printf("Enter salary: ");
        scanf("%d",&employees[i].salary);
    }


    FILE *managerfile =fopen("managers.txt","w");
    FILE *employeeFile = fopen("employees.txt","w");

    if (managerFile == NULL || workerFile == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if(strcasecmp(employees[i].role, "Manager") == 0) {
            fprintf(managerFile, "ID: %d, Name: %s, Salary: %d\n", employees[i].id, employees[i].name, employees[i].salary);
        } else if (strcasecmp(employees[i].role, "Worker") == 0) {
            fprintf(workerFile, "ID: %d, Name: %s, Salary: %d\n", employees[i].id, employees[i].name, employees[i].salary);
        }
    }


    

    fclose(managerFile);
    fclose(workerFile);

    return 0 ;

}
