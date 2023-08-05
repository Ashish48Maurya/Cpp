// 3 1 0 2 0 5    -->   3 1 2 5 0 0
// This sum is application of bubble sort
//Lecture No.: 35       --> College Wallah
#include<iostream>
using namespace std;
int main(){
    int arr[] = {3,1,0,2,0,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=n-1; i>=0; i--){
        bool flag = false;
        int j=0;
            while(i!=j){
                if(arr[j]==0 && arr[j+1]!=0){
                    swap(arr[j],arr[j+1]);
                }
                j++;
            flag = true;
            }
        if(flag==0){
            break;
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}