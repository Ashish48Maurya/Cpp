#include<iostream>
using namespace std;
int main(){
    char ch = 'a';
    cout<<ch<<endl;

    cout<<(int)ch<<endl;

    cout<<(ch+1)<<endl;
    
    cout<<(char)(ch+1)<<endl;

    int a=45;
    float b=45.55;
    cout<<"the value of a is "<<(float)a<<endl;
    cout<<"the value of b is "<<(float)b<<endl;
    cout<<"the value of b is "<<(int)b;

    cout<<"The expression  is "<<a+b<<endl;
    cout<<"The expression is "<<a+ int(b)<<endl;
    cout<<"The expression is "<<a+ (int)b;
    return 0;
}