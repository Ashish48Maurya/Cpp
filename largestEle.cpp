//If all Elements are unique
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {1,2,5,6,9,0};
    int size = 6;
    int largestEle = INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i]>largestEle){
            largestEle = arr[i];
        }
    }
    cout<<"Largest Element: "<<largestEle<<endl;
    return 0;
}