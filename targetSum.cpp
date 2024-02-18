#include<iostream>
#include<vector>
using namespace std;

int func(vector<int> arr,int index, int size, int sum){
    // if(sum==0){
    //     return 1;
    // }
    // if(sum<0 || index==size){
    //     return 0;
    // }                    //This Code will give false result for this case : vector<int> arr = {1,0}; int sum = 5;  ans should be 2 but giving 1 only

    if(index==size){
        return sum==0;
    }

    return func(arr,index+1,size,sum) + func(arr,index+1,size,sum-arr[index]);
}
int main(){
    vector<int> arr = {1,5,4};
    int sum = 5;

    // vector<int> arr = {1,0};
    // int sum = 1;


    int index = 0;
    int size = arr.size();
    cout<<func(arr,index,size,sum);
    return 0;
}