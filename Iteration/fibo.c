#include<stdio.h>

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1)+fib(n-2);
}

void printfib(int m){
    for (int i = 0; i <= m; i++)
    {
        printf("%d",fib(i));
    }
    printf("\n");
    
}
int main(){
    int m;
    printf("Enter the number of terms: ");
    scanf("%d",&m);
    printfib(m);
    return 0;
    
}