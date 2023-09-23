#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,3,4,1,2,3,4};
    int size = 7;
    int ans = -1;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]==arr[j]){
                arr[i] = -1;
                arr[j] = -1;
            }
        }
    }
    for(int i=0; i<size; i++){
        if(arr[i]>0){
            cout<<"Unique Element in the above array is: "<<arr[i]<<endl;
        }
    }

    return 0;
}