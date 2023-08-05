#include<iostream>
using namespace std;
void countsort(int arr[], int n){
    int k=arr[0];                     //  
    for(int i=0; i<n; i++){           // array me max element konsaa hai iske madat se pata chala
        k=max(k,arr[i]);              //
    }

    int count[n]={0};           //
    for(int i=0; i<n; i++){      //  kon sa element kitne baar repeat ho raha hai pata kiye
        count[arr[i]]++;         //
    }

    for(int i=1;i<=k; i++){     //  updated array banaye
        count[i] += count[i-1];   // 
    }

    int solarr[n];
    for(int i=n-1; i>=0; i--){           // solution array
        solarr[--count[arr[i]]]=arr[i];
    }
    
    for(int i=0; i<n; i++){
        arr[i]=solarr[i];
    }
}
int main(){
    int arr[]={1,3,2,3,4,1,6,4,3};
    countsort(arr,9);
    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}