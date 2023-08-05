#include<iostream>
using namespace std;
int Sum(int a , int b){
    int c=a+b; ;
    return c;
}
//      call by reference
void Swap1(int &a , int &b){
// & --> iska matlab function siddha address pe jaake work perform karega
// i.e   ram me jaha dono integer rahate hai udhar jaake change karenge
// i.e   permanent change jiske wajha se original value me bhi change aata hai 
    int temp = a;
    a=b;
    b=temp;
}
//      call by value
void Swap(int a , int b){
    // yaha x and y  ka copy ban ke aaye
    // virtual change
    int temp = a;
    a=b;
    b=temp;
}
int main(){
    int x=1 , y=2;
   Swap(x,y);
   cout<<"The value of x is: "<<x<<endl<<"The value of y is: "<<y<<endl;
    //  hamesha original value jo hai wahi print hota hai
   Swap1(x,y);
   cout<<"The value of x is: "<<x<<endl<<"The value of y is: "<<y<<endl;
    //  hamesha original value jo hai wahi print hota hai
 return 0;
}


// In; short Call By Value tabhi use karte hai jab value modify nahi karna ho
// and, Call By Reference tabhi use karte hai jab value modify karna ho