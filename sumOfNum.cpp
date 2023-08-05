#include<iostream>
using namespace std;

int sum(int a, int b){
  int c = a+b;
  return c;
  }


int main(){
  
   int num1,num2;
   cout<<"enter the value of num1";
   cin>>num1;
   cout<<endl;

   cout<<"enter the value of num2";
   cin>>num2;
   cout<<endl;

   cout<<"the sum of the number is "<<sum(num1,num2);


    return 0;
}