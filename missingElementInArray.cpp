//given a array of 9 element from 0 to 9 out of which one element is missing find the missing element
#include<stdio.h>
int main(){
    int arr[] = {9,0,1,3,5,6,7,8,2};
    int sum1=0, sum2=0 , ans=sum2-sum1;
    for(int i=0; i<=9; i++){
        sum2+=i;
    }

    for(int i=0; i<9; i++){
        sum1+=arr[i];
    }
    printf("%d is the missing Element",ans);
    return 0;
}