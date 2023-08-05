       //function prototype

/*   #include<iostream>
using namespace std;
int main(){
  
   int num1,num2;
   cout<<"enter the value of num1";
   cin>>num1;

   cout<<"enter the value of num2";
   cin>>num2;

   cout<<"the sum of the number is "<<sum(num1,num2);


    return 0;
}

int sum(int a, int b){
  int c = a+b;
  return c;
  }
 */

  //upar wala code execute nahi ho raha hai abh iss pproblem ko solve karne ke liye ham function prototype 
  // ki madat lenge
  // function prototype ye assurity dilayega compiler ko ki main function ke baad bahr jaake bhi 
  // dundho tumhe sum dikh jaayega


#include<iostream>
using namespace std;
int sum(int a, int b);
int main(){
  
   int num1,num2;
   cout<<"enter the value of num1";
   cin>>num1;

   cout<<"enter the value of num2";
   cin>>num2;

   //here num1 and num2 are called as actual parameter
   //and value of num1 and num2 are called as formal parameter

   cout<<"the sum of the number is "<<sum(num1,num2);


    return 0;
}

int sum(int a, int b){
  int c = a+b;
  return c;
  }
