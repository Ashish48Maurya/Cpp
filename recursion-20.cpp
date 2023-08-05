//Print array without using loop
#include<stdio.h>
void print(int arr[], int idx, int n){
    if(idx==n){
        return;
    }
    printf("%d\n",arr[idx]);
    print(arr,idx+1,n);
}
int main(){
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    print(arr,0,n);
    return 0;
}