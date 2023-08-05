//Swap 2 Number without using third variable
#include<iostream>
using namespace std;
int main(){
int a,b,temp;
cout<<"Enter two Numbers: "<<endl;
cin>>a>>b;
cout<<"Value of a and b before swaping is: "<<a<<" "<<b<<" respectively"<<endl;
a=a+b;
b=a-b;
a=a-b;
cout<<"After swapping a and b becomes: "<<a<<" "<<b<<endl;
    return 0;
}