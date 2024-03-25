#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int findCost(vector<int> v){
    priority_queue<int,vector<int> , greater<int>> pq;
    for(auto i : v){
        pq.push(i);
    }
    int costOfJoiningRopes = 0;
    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int mergedLength = first+second;
        pq.push(mergedLength);
        costOfJoiningRopes += mergedLength;
    }
    return costOfJoiningRopes;
}
int main(){
    vector<int> v = {4,3,2,6};
    int ans = findCost(v);
    cout<<"Cost Required: "<<ans<<endl;
    return 0;
}