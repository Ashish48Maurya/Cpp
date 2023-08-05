#include<iostream>
using namespace std;
int main(){
    //array Eg
    int marks[4] = {23, 45, 56, 89};

    int mathmarks[4];
    mathmarks[0] = 227;
    mathmarks[1] = 738;
    mathmarks[2] = 378;
    mathmarks[3] = 578;

    cout<<"these are math marks"<<endl;
    cout<<mathmarks[0]<<endl;
    cout<<mathmarks[1]<<endl;
    cout<<mathmarks[2]<<endl;
    cout<<mathmarks[3]<<endl;
    cout<<endl;

    cout<<"these are marks"<<endl;
    cout<<marks[0]<<endl;
    cout<<marks[1]<<endl;
    cout<<marks[2]<<endl;
    cout<<marks[3]<<endl;
    cout<<endl;


    //pointers and arrays
    int* p = marks;
    cout<<"the value of marks [0] is "<<*p<<endl;
    cout<<"the value of marks [1] is "<<*(p+1)<<endl;
    cout<<"the value of marks [2] is "<<*(p+2)<<endl;
    cout<<"the value of marks [3] is "<<*(p+3)<<endl;










    return 0;
} 