#include<iostream>
#include<vector>
using namespace std;

int func(vector<int> arr, int index,int sum, int size){
    if(index==size){
        if(sum==0){
            return 1;
        }
        else{
            return 0;
        }
    }
            //No + increment                //yes + No Increment
    return func(arr,index+1,sum,size) + func(arr,index,sum-arr[index],size);
}

int main(){
    vector<int> arr = {1,2,3,4};
    int index = 0;
    int sum = 6;
    int size = arr.size();
    cout<<func(arr,index,sum,size)<<endl;
    return 0;
}