//1st rotation => {5,1,2,3,4}
//2nd rotation => {4,5,1,2,3}

#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int K = 2;
    K = K%n;    //Because K may be greater than n;
    int j = 0;
    int arr1[n];

    //Rotating last K elements
    for(int i=n-K; i<n; i++){
        arr1[j++] = arr[i];
    }

    //Rotating first n-K elements
    for(int i=0 ; i<=K ; i++){
        arr1[j++] = arr[i];
    }

    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    return 0;
}