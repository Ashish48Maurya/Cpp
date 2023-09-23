// Given an array => {1,0,9,5,0,3} take all zeroes to the end of the array without changing relative order of the other elements

#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> vec = {1,0,9,5,0,3};
    int n = vec.size();
    bool flag = false;

    for(int i=n-1; i>=0; i--){
        int j = 0;
        while(j!=i){
            if(vec[j] == 0 and vec[j+1]!=0){
                swap(vec[j],vec[j+1]);
                flag = true;
            }
            j++;
        }
        if(!flag) break;
    }
    
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    
    return 0;
}