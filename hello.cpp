#include<bits/stdc++.h>
using namespace std;
void ans(vector<vector<int>> nums){
    int mini,maxi;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i=0; i<nums.size(); i++){
        pq.push({nums[i][0],{i,0}});
        maxi = max(maxi,nums[i][0]);
    }
    mini = pq.top().first;

    vector<int> ans(2);
    ans[1] = maxi;
    ans[0] = mini;
    pair<int,pair<int,int>> ele;
    int i,j;
    while(pq.size()==nums.size()){
        ele = pq.top();
        i = ele.second.first; //row
        j = ele.second.second; //column
        mini = ele.first;
        if(j+1<nums[i].size()){
            pq.push({nums[i][j+1],{i,j+1}});
            maxi = max(maxi,nums[i][j+1]);
        }
        if(ans[1]-ans[0] > maxi-mini){
            ans[0] = mini;
            ans[1] = maxi;
        }
    }
    return ans;
}
int main(){

}