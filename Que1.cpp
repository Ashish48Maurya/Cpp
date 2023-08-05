//Swap two number without using third variable
#include<stdio.h>
int main(){
    int num1,num2,temp;
    printf("Enter the value of num1 and num2: ");
    scanf("%d%d",&num1,&num2);
    printf("Value of num1 and num2 before swaping is %d and %d resp. \n",num1,num2);
    num1=num1+num2;
    num2=num1-num2;
    num1=num1-num2;
    printf("Value of a and b after swaping is %d and %d resp.",num1,num2);
    return 0;
}

//check whether number is even or odd using modulus and conditional operator
// #include<stdio.h>
// int main(){
//     int num;
//     printf("Enter the value of num: ");
//     scanf("%d",&num);
//     if(num%2==0){
//         printf("Number is even");
//     }
//     else{
//         printf("Number is odd");
//     }
//     return 0;
// }

// //Count Number of digits in a given Number
// #include<stdio.h>
// int main(){
//     int num,digits=0;
//     printf("Enter the value of num: ");
//     scanf("%d",&num);
//     while(num!=0){
//         num=num/10;
//         digits++;
//     }
//     printf("Number of Digits in a given Number is: %d",digits);
//     return 0;
// }


//Roots of Quadratic Equation having Coefficients a,b,c
// #include<stdio.h>
// #include<math.h>
// int main()
// {
//    int a, b, c, d, root1, root2, realPart, imaginaryPart;
//    printf("Enter Value of Coefficients: ");
//    scanf("%d%d%d",&a,&b,&c);
//    d = (b*b)-4*a*c;
//    if( d>1 )
//    {
//      root1 = (-b+sqrt(d))/2*a;
//      root2 = (-b-sqrt(d))/2*a;
//      printf("Roots are %d and %d\n", root1, root2);
//    }
//    else if(d==0)
//    {
//      root1 = root2 = -b/2*a;
//      printf("Roots are %d and %d\n", root1, root2);
//    }
//    else
//    {
//      realPart = -b/2*a;
//      imaginaryPart = sqrt(d)/2*a;
//      printf("root1 = %d + i(%d)\n", realPart, imaginaryPart);
//      printf("root1 = %d - i(%d)\n", realPart, imaginaryPart);
//    }
//    return 0;
// }

//Simple Calculator using Switch Case
// #include <stdio.h>
// int main(){
//   char op;
//   int num1, num2;
//   printf("Enter an operator (+, -, *, /): ");
//   scanf("%c",&op);
//   printf("Enter two operands: ");
//   scanf("%d%d",&num1,&num2);
//   switch(op) {
//     case '+':
//       printf("%d + %d = %d", num1, num2, num1 + num2);
//       break;
//     case '-':
//       printf("%d - %d = %d", num1, num2, num1 - num2);
//       break;
//     case '*':
//       printf("%d * %d = %d", num1, num2, num1 * num2);
//       break;
//     case '/':
//       printf("%d / %d = %d", num1, num2, num1 / num2);
//       break;
//     default:
//       printf("Invalid Operator");
//   }
//   return 0;
// }

//Reverse of a  Number
// #include<stdio.h>
// int main(){
//     int n,reverse=0,sum=0,remainder;
//     printf("Enter the Number: ");
//     scanf("%d",&n);
//     while (n!=0)
//     {
//         remainder=n%10;
//         reverse = reverse*10 + remainder;
//         sum+=remainder;
//         n=n/10;
//     }
//     printf("Reverse of a given Number is: %d",reverse);
//     printf("\nSum of digits of a Number is: %d",sum);
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     for(int i=1; i<=5; i++){
//         for(int j=i; j>=1;j--){
//             printf("%d ",j);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int ch=65;
//     for(int i=1; i<=5; i++){
//         for(int j=5; j>i; j--){
//             printf(" ");
//         }
//         for(int k=1; k<=i; k++){
//             printf("%c",ch++);
//         }
//         ch--;
//         for(int l=1;l<i;l++){
//             printf("%c",--ch);
//         }
//         printf("\n");
//         ch=65;
//     }
//     return 0;
// }

// #include <stdio.h>
// int main() {
//    int year;
//    printf("Enter a year: ");
//    scanf("%d", &year);
//    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
//       printf("%d is a leap year.", year);
//    }
//    else {
//       printf("%d is not a leap year.", year);
//    }
//    return 0;
// }

/* 
 * C program to find maximum and minimum between two numbers using functions
 */


// #include <stdio.h>
// int max(int num1, int num2)
// {
//     return (num1 > num2) ? num1 : num2;
// }

// int min(int num1, int num2) 
// {
//     return (num1 > num2) ? num2 : num1;
// }
// int main() 
// {
//     int num1, num2, maximum, minimum;

//     printf("Enter any two numbers: ");
//     scanf("%d%d", &num1, &num2); 

//     maximum = max(num1, num2); 
//     minimum = min(num1, num2);  

//     printf("\nMaximum = %d\n", maximum);
//     printf("Minimum = %d", minimum);
//     return 0;
// }