#include<iostream>
using namespace std;
int main(){
    //pointer is a data type which holds the address of other data type

    int a=3;
    int* b=&a; 
    // &----->  (adress of ) operator
    cout<<"the address of a is "<<&a<<endl;
    cout<<"the address of a is "<<b<<endl;

    //*----> (value at) Dereference operator
    cout<<"the value at address b is  "<<*b<<endl;
    return 0;
}