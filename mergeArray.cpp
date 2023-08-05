#include<iostream>
using namespace std;
int main(){
int arr1[] = {1,2,3,4,5,6};
int arr2[] = {6,5,4,3,2,1};
int i,j;
int num = sizeof(arr1)/sizeof(int) + sizeof(arr2)/sizeof(int);
int num1 = sizeof(arr1)/sizeof(int);
int arr3[num];
for(i=0; i<6; i++){
    arr3[i] = arr1[i];
}

for(j=0; j<6; j++){
    arr3[num1+j] = arr2[j];
}
for(i=0; i<num; i++){
    cout<<arr3[i]<<" ";
}
return 0;
}