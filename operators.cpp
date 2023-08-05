#include<iostream>
using namespace std;

int main(){
    int a=4, b=5;
    cout<<"Following are the type of operators inn C++"<<endl;
    cout<<"The value of a+b is "<<a+b<<endl;
    cout<<"The value of a-b is"<<a-b<<endl;
    cout<<"The value of a*b is"<<a*b<<endl;
    cout<<"The value of a/b is"<<a/b<<endl;
    cout<<"The value of a%b is"<<a%b<<endl;
    cout<<"The value of a ++ is"<<a ++<<endl;
    cout<<"The value of a -- is"<<a--<<endl;
    cout<<"The value of ++a is"<<++a<<endl;
    cout<<"The value of --a is"<<--a<<endl;
    cout<<endl; //space create karne ke liye aise karne ka 

    
    cout<<"Following are the comparision opertaors in C++"<<endl;
    cout<<"The value of a=b is"<<(a==b)<<endl;
    cout<<"The value of a!=b is"<<(a!=b)<<endl;
    cout<<"The value of a>=b is"<<(a>=b)<<endl;
    cout<<"The value of a<=b is"<<(a<=b)<<endl;
    cout<<"The value of a>b is"<<(a>b)<<endl;
    cout<<"The value of a<b is"<<(a<b)<<endl;
    cout<<endl;

    cout<<"Following are the logical opertaors in C++"<<endl;
    cout<<"The value of this logical and operator ((a==b) && (a<b)) is:"<<((a==b) && (a<b))<<endl;
    cout<<"The value of this logical or operator ((a==b) || (a<b)) is:"<<((a==b) || (a<b))<<endl;
    cout<<"The value of this logical not operator (!(a==b)) is:"<<!(a==b)<<endl;
    return 0; 
}