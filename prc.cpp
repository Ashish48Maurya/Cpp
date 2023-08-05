// // #include<iostream>
// // using namespace std;
// // int main(){
// //     int arr1[] = {2,2,2,3};
// //     int arr2[] = {2,2,2,4};
// //     int n1= sizeof(arr1)/sizeof(int) , n2= sizeof(arr2)/sizeof(int) , count=0;
// //     for(int i=0; i<n1; i++){
// //         if(arr1[i]==arr2[i]){
// //             ++count;
// //         }
// //     }
// //     if(count==n1){
// //         cout<<"Arrays are Symmetrical"<<endl;
// //     }
// //     else if(n1!=n2){
// //         cout<<"Arrays are Asymmetrical"<<endl;
// //     }
// //     else{
// //         cout<<"Arrays are Asymmetrical"<<endl;
// //     }
// //     return 0;
// // }

// #include<stdio.h>
// bool isSame(int arr1[],int arr2[],int n1, int n2,int count){
//     for(int i=0; i<n1; i++){
//         if(arr1[i]==arr2[i]){
//             ++count;
//         }
//     }
//     if(count==n1){
//         return 1;
//     }
//     else if(n1!=n2){
//         return 0;
//     }
//     else{
//         return 0;
//     }
// }
// int main(){
//     int arr1[] = {1,4,3,3};
//     int arr2[] = {2,4,3,3};
//     int n1 = sizeof(arr1)/sizeof(int);
//     int n2 = sizeof(arr2)/sizeof(int);
//     if(isSame(arr1,arr2,n1,n2,0)){
//         printf("Yes");
//     }
//     else{
//         printf("No");
//     }
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int arr1[] = {1,2,3,1,1,2},count=0;
//     for(int i=0; i<6; i++){
//         for(int j=i; j<6; j++){
//             if(arr1[i]==arr1[j]){
//                 ++count;
//             }
//         }
//     }
//     printf("Number of Duplicates in Array is: %d",count);
//     return 0;
// }

// #include<stdio.h>
// int power(int num,int n){
//     int prd=1;
//     for(int i=0; i<n; i++){
//         prd*=num;
//     }
//     printf("%d",prd);
// }
// int main(){
//     int num;
//     scanf("%d",&num);
//     power(num,3);
//     return 0;
// }

#include<stdio.h>
int main(){
    int arr1[3][2] = {{1,2},
                      {3,2},
                      {0,2}};
    int arr2[2][1] = {{1},
                      {2}};
    int ans[3][1],sum=0;
    for(int i=0; i<3; i++){
        for(int j=0; i<1;j++){
            for(int k=0; k<2; k++){
                sum+=arr1[i][k]*arr2[k][j];
            }
            ans[i][j] = sum;
            sum=0;
        }
    }  
    for(int i=0; i<3; i++){
        for(int j=0; j<1;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }                
    return 0;
}