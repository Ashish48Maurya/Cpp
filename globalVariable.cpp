#include<iostream>
using namespace std;
int i = 10;  // this is defined as global variable which can be use throughout our prograam
int main(){
int i = 100;
cout<<i<<endl;   // prints local variable wala 'i' ;
cout<<::i<<endl; // Now prints our global variable value;

//*****************Reference Variable***************
//agar kisi ka naam hai Rohan(asli naam) or usse " Banti " bhi bulate hai or "chinti" bhi 
// toh Rohan is variable and all other name is reference variable 

// float x= 455;
//float & y= x;   //here y is reference variable 
//  cout<<x<<endl;
// cout<<y<<endl;
return 0;
}