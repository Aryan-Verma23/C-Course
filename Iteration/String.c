#include<stdio.h>
#include<string.h>
struct mystruct{
    int myval;
    char fieldname;
    char String[30];

};
int main(){
  struct mystruct m1 ={13 , "A" , "someText"};
  printf("%d %c %s",m1.myval,m1.fieldname,m1.String);
   
}