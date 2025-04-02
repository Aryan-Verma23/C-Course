#include <stdio.h>

void findDivisors(int n) {
    printf("Divisors of %d: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
int main() {
    int a;  
    printf("Enter a number: ");
    scanf("%d", &a);
    
    if (a < 0) {
        printf("Factorial not defined for negative numbers.\n");
    } else {
   
        findDivisors(a);
        printf("Factorial of %d: %d\n", a, factorial(a));
    }

    return 0;
}
