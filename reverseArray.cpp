#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Original Array is: ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    int i=0, j=n-1-i ,temp;

    while(i<j){
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
    printf("Reverse of a array is: ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}