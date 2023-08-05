#include<stdio.h>
int main(){
    int arr[] = {1,2,3,4,1,5,6};
    int length = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<length; i++){
        for(int j=i+1; j<length; j++){
            if(arr[i]==arr[j]){
            printf("%d is the duplicate Element in Array",arr[i]);
            }
        }
    }
    return 0;
}