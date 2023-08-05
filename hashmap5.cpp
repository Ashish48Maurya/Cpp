// Target sum problem;
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> targetSumPair(vector<int> &vec, int target){
vector<int> ans(2,-1);
unordered_map<int , int>  up; 
for(int i=0; i<vec.size(); i++){
    if(up.find(target - vec[i])!=up.end()){
        ans[0] = up[target - vec[i]];
        ans[1] = i;
    }
    else{
        up[vec[i]] = i;
    }
}

return ans;

}

int main(){
cout<<"Enter Size of Vector: ";
int size;
cin>>size;
vector<int> vec(size);
cout<<"Enter vector Elemets: ";
for(int i=0; i<size; i++){
    cin>>vec[i];
}

int target;
cout<<"Enter Target Sum: ";
cin>>target;

vector<int> ans = targetSumPair(vec , target);
cout<<ans[0]<<" "<<ans[1]<<endl;

return 0;
}