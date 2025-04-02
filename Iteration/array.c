#include<stdio.h> 

    void printarray(int arr[],int size){
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
    }
    printf("\n");
}
void reversearray(int arr[],int size);
int start = 0; int end = size-1;int temp = 0;
while(end>start){
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
}
int main(){
    int arr[5];
    int size;

    for(int i = 0;i<size;i++){
        scanf("%d",&arr[i]);
    }
   
    printarray(arr,size);
    reversearray(arr,size);
    printarray(arr,size);

    return 0;
}



