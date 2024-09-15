#include<iostream>
using namespace std;
int main(){
    cout<<"Enter Three Integers ";
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b && a>c){
        cout<<"Largest Number is "<<a;
    }else if(b>a && b>c){
        cout<<"Largest Number is "<<b;
    }else{
        cout<<"Largest Number is "<<c;
    }

    return 0;
}

