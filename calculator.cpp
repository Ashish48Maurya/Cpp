// #include<iostream>
// using namespace std;
// int main(){
// while(1){
// char op;
//  float num1, num2;
//  cout << "Enter two numbers: "<< endl;
//  cin >> num1 >> num2;
//  cout << "Enter an operator (+, -, *, /): ";
//  cin >> op;
//  switch (op) {
//  case '+':
//  cout << num1 << " + " << num2 << " = " << num1 + num2;
//  break;
//  case '-':
//  cout << num1 << " - " << num2 << " = " << num1 - num2;
//  break;
//  case '*':
//  cout << num1 << " * " << num2 << " = " << num1 * num2;
//  break;
//  case '/':
//  cout << num1 << " / " << num2 << " = " << num1 / num2;
//  break;
//  default:
//  cout << "Error! The operator is not correct";
//  // operator doesn't match with any case constant (+, -, *, /)
//  break;
//  }
//  cout<<endl;
// }
// return 0;
// }

#include<stdio.h>
int main(){
    char op;
    int num1,num2;
        printf("Enter the value of num1 and num2: ");
        scanf("%d%d",&num1,&num2);
        printf("Enter the value f Operator: ");
        scanf(" %c",&op);
        switch(op){
        case '+':
        printf("Value of %d + %d = %d",num1,num2,num1+num2);
        break;
        case '-':
        printf("Value of %d - %d = %d",num1,num2,num1-num2);
        break;
        default:
        printf("Try Again");  
        break;
        }
    return 0;
}