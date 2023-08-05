#include<iostream>
using namespace std;
int main(){
int a,b;
cin>>a>>b;
cout<<"Value of a is: "<<a<<"value of b is: "<<b<<endl;
b=a+b-b;
a=a+b-b;
cout<<"Value of a is: "<<a<<"value of b is: "<<b<<endl;
return 0;
}