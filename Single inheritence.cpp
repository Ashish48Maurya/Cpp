#include<iostream>
using namespace std;
class Base{
    int data1;
    public :
    int data2 = 20;
    void setdata();
    int getdata1();
};
void Base :: setdata(){
    data1 = 10;
}

int Base :: getdata1(){
    return data1;
}

class Derived : public Base{
    int data3;
    public:
    void process();
    void display();
};
void Derived::process(){
    data3 = data2 * getdata1();
}

void Derived :: display(){
    cout<<"Value of data 1 is "<< getdata1() <<endl;
    cout<<"Value of data 2 is "<<   data2 <<endl;
    cout<<"Value of data 3 is "<<  data3 <<endl;
}
int main(){
    Derived der;
    der.setdata();
    der.process();
    der.display();
    return 0;
}