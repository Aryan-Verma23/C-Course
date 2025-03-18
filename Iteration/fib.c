#include <stdio.h>

// Function to compute Fibonacci number recursively
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print first m Fibonacci numbers
void printFibonacci(int m) {
    for (int i = 0; i < m; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int m;
    printf("Enter the number of Fibonacci numbers to print: ");
    scanf("%d", &m);
    
    printFibonacci(m);

    return 0;
}
