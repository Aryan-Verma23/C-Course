#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter the values of a,b,c: ");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b){
        if(a>c){
            printf("%d is greatest\n",a);

        }
    }
        if(b>a){
            if(b>c){
                printf("%d is greatest\n",b);

            }
        }
    if(c>a){
        if(c>b){
            printf("%d is greatest\n",c);
        }
    }    
    return 0;
    
}