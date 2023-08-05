#include<stdio.h>
int main(){
    int arr[] = {1,2,3,4,2,5,2};
    //int n = sizeof(arr)/sizeof(arr[2]);
    int n = sizeof(arr)/sizeof(int);
    printf("%d",n);
    return 0;
}