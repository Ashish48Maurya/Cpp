#include<iostream>
using namespace std;
int main(){
   
// manipulators in C++
   int  a=8, b=95, c=633;
    cout<<"the value of a is: "<<setw(4)<<a<<endl;
    cout<<"the value of b is: "<<setw(4)<<b<<endl;
    cout<<"the value of c is: "<<setw(4)<<c<<endl;

    cout<<"the value of a without setw is "<<a<<endl;
    cout<<"the value of b without setw is "<<b<<endl;
    cout<<"the value of c without setw is "<<c<<endl;

    return 0;
}