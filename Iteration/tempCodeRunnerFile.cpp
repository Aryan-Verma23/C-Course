int main(){
    int numStudents;
    Student students[MAX_STUDENTS];

    printf("Enter number of students: ");
    scanf("%d", &numStudents); 
     sortStudents(students, numStudents);
    displayStudents(students, numStudents);

    printf("\nTop Student: %s with Average: %.2f\n", 
           students[0].name, students[0].average);

    return 0;

}