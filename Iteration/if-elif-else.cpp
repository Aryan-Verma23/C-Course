#include<iostream>
using namespace std;

int main(){
    int savings;
    cout<<"Enter the savings ";
    cin>>savings;
    if(savings>5000){
        cout<<"Go Party\n";
    }else if(savings>3000){
        cout<<"Can trip\n";
    }else{
        cout<<"Study at home idiot!!!\n";
    }
    return 0;
}