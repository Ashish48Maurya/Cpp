#include<iostream>
using namespace std;
class Base1{
protected:
    int base1int;
public:
    void set_base1int(int a){
    base1int = a;
    }
};
class Base2{
protected:
    int base2int;
public:
    void set_base2int(int a){
    base2int = a;
    }
};
class Derived : public Base1 , public Base2{
public:
    void show(){
    cout<<"The value of base1 is: "<< base1int <<endl;
    cout<<"The value of base2 is: "<< base2int <<endl;
    cout<<"There sum is :" << base1int + base2int <<endl;
    }
};
int main(){
    Derived d;
    d.set_base1int(20);
    d.set_base2int(20);
    d.show();
return 0;
}


             //    Ambiguity ------>  dono same chij de rahe hai kiska lu
// #include<iostream>
// using namespace std;
// class Base1{
// public:
//     void Greet(){
//     cout<<"How are you"<<endl;
//     }
// };
// class Base2{
// public:
//     void Greet(){
//     cout<<"Kaise ho"<<endl;
//     }
// };
// class Derived : public Base1 , public Base2{
// int a;
// public:
//     void Greet(){
//         Base1 :: Greet();       // kiska Greet call karwana hai usko aise bolte hai
//         Base2 :: Greet();
//     }
// };
// int main(){
//     Derived d;
//     d.Greet();
// return 0;
// }