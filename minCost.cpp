#include<iostream>
#include<queue>
using namespace std;
int minCost(int arr[]){
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for(int i=0; i<4; i++){
        pq.push(arr[i]);
    }
    while(pq.size() != 1){
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();
    int count = first + second;
    sum += count;
    pq.push(count);
    }
    return sum;
}
int main(){
int arr[] = {4,3,2,6};
cout<<minCost(arr)<<endl;
}