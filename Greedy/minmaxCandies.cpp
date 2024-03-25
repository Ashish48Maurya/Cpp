#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> findMinMax(vector<int> candies, int K , int N){
    vector<int> ans;

    //For Min Cost  ->  {1,2,3,4};
    sort(candies.begin(),candies.end());
    int minCost = 0;
    int buy = 0;
    int free = N-1;
    while(buy<=free){
        minCost += candies[buy];
        buy++;
        free = free-K;
    }
    ans.push_back(minCost);
    
    //For Max Cost
    int maxCost = 0;
    buy = N-1;
    free = 0;
    while(free<=buy){
        maxCost += candies[buy];
        buy--;
        free = free+K;
    }
    ans.push_back(maxCost);
    return ans;
}

int main(){
    vector<int> candies = {3,2,1,4};
    int K = 2;
    int N = 4;
    vector<int> ans = findMinMax(candies,K,N);
    cout<<"Min-Cost: "<<ans[0]<<" & "<<"Max-Cost: "<<ans[1];
    return 0;
}