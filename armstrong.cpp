#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num = n;
    int sum=0;
    while(num>0){
        int  rem=num%10;
        sum=sum+(rem*rem*rem);
        num=num/10;
    }
    if(sum==n){
        cout<<"The number is armstrong number";
    }
    else{
        cout<<"the number is not a armstrong number";
    }

    return 0;
}