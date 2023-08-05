//Binary search in 2-D Array
#include<iostream>
#include<vector>
using namespace std;
int targetEle(vector<vector<int>> &v , int target){
int n = v.size(); // Row
int m = v[0].size(); // Column

//Assume in 1-D form [1,2,3,4,7,10,11,13,15,18,20,28]
int l = 0, r = n*m-1;
while(r>=l){
    int mid = l + (r-l)/2;
    int i = mid/m, j = mid%m;
    if(v[i][j] == target){
        return 1;
    }
    else if(v[i][j]>target){
        r=mid-1;
    }
    else{
        l=mid+1;
    }
}
return 0;
}
int main(){
vector<vector<int>> v = {{1,2,3,4},
                         {7,10,11,13},
                         {15,18,20,28}};
int target;
cout<<"Enter the Target element: ";
cin>>target;
int ans = targetEle(v,target);
cout<<ans;
if(ans==1){
    cout<<"Target Element is present"<<endl;
}
else{
    cout<<"Target Element is not present in Array"<<endl;
}
return 0;
}