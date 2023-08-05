/*
jab bhi user ko array during run time dena raheta hai toh usse ham memory allocate 
karake dete hai usse during run time ki wo apna array bana sake;
int* arr = new int[n]  ----> for 1-D array formation

OR AGAR
user ko 2-D array form karna hai during run time toh dynamic memory allocate karate hai
as
 int** arr = new int*[n];
*/


// #include<iostream>
// using namespace std;
// int main(){
// int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
// int i, j ;
// cout<<"Enter the value of i and j"<<endl;
// cin>>i>>j;
// cout<<arr[i][j]<<endl;
// return 0;
// }

// #include<stdio.h>
// using namespace std;
// int main(){
// int arr[3][3] = {
//                  {1,2,3},
//                  {4,5,6},
//                  {7,8,9}
//                 };
// for(int i=0; i<3; i++){
//     for(int j=0; j<3; j++){
//         printf("%d",arr[i][j]);
//         printf(" ");
//     }
//     printf("\n");
// }
// return 0;
// }

#include<stdio.h>
using namespace std;
int main(){
int arr[3][3] = {
                 {1,2,3},
                 {4,5,6},
                 {7,8,9}
                };
printf("Enter the value of 'i' and 'j' \n");
int i,j;
scanf("%d%d",&i,&j);
printf("%d",arr[i][j]);
    return 0;
}