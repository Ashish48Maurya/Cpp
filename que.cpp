// #include<stdio.h>
// int main(){
//     int num = 0;
// for(int i=1; i<=50; i++){
//     if(i%2==0 || i%3==0 || i%5==0){
//     continue;
//     }
//     else{
//     num++;  
//     }
// }
// printf("Nuber of digits not divisible by 2,3 and 5 is: %d",num);
// return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
// int num = 123;
// int i=0;
// while(num>0){
//     num = num/10;
//     i++;
// }
// cout<<i<<endl;
// return 0;
// }

// #include<stdio.h>
// int main(){
//     int num,res;
//     char x;
//     do{
//             printf("Enter the value of num: ");
//             scanf("%d\n",&num);
//             printf("Enter the operator: ");
//             scanf("%c",&x);
//             int num1,num2;
//             printf("Enter the value of num1 and num2: ");
//             scanf("%d%d",&num1,&num2);
//             switch(x){
//                 case '+':
//                 res = num1+num2;
//                 break;
//                 case '-':
//                 res = num1-num2;
//                 break;
//                 case '*':
//                 res = num1*num2;
//                 break;
//                 case '/':
//                 res = num1/num2;
//                 break;
//                 default:
//                 printf("Hello Hello");
//             }

//             printf("\nValue of %d %c %d is: %d",num1,num2,x,res);
        
//     }while(num == 1);
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int num,num1,num2,res;
//     char x;
//     do{
//     printf("Enter the valu eof num: ");
//     scanf("%d\n",&num);
//     printf("Enter the value of Operator: ");
//     scanf("%c",&x);
//     printf("Enter the value of num1 and num2: ");
//     scanf("\n%d%d",&num1,&num2);
//     switch(x){
//         case '+':
//         res = num1+num2;
//         break;
//         case '-':
//         res = num1-num2;
//         break;
//         default:
//         printf("Try Again");
//     }
//     }while(num==1);
//     return 0;
// }