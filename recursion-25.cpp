// check whether a given element exist in a array or not using recursion
// input = {1,2,3,4,5},  target = 4  ,  output->Yes

// self-Work --> check whether element is present or not , only for zeroeth position
//Asumption --> Recursion will check from 1th to (n-1)th position
#include<iostream>
using namespace std;
bool check(int arr[], int n, int i, int x){
    if(i==n){
        return false;
        // Elements are present only till (n-1)th position 
    }

    return (arr[i]==x) || (check(arr, n, i+1, x));

}
int main(){
    int arr[] = {1,2,3,4,5,9,0,7};
    int n = 8;
    int x = 5; // x -> target element;
    int i=0;
    bool result = check(arr,n,i,x);
    if(result) cout<<"Yes";
    else cout<<"No";
    return 0;
}