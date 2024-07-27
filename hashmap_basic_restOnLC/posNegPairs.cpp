#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {1,-3,5,-1,9,0,-1,8,-9,1,-8,3,-1};
    vector<int> negEle;
    vector<int> ans;
    unordered_map<int,int> posEle;
    for(auto ele : v){
        if(ele < 0){
            negEle.push_back(ele);
        }
        posEle[ele]++;
    }

    sort(negEle.begin(),negEle.end());

    for(int i=negEle.size()-1; i>=0; i--){
        int ele = abs(negEle[i]);
       
        if(posEle[ele] > 0){
            ans.push_back(negEle[i]);
            ans.push_back(ele);
            posEle[ele]--;
        }    
        
    }

    for(auto ele : ans){
        cout<<ele<<" ";
    }
    
    return 0;
}