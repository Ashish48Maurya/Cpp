#include<iostream>
#include<queue>
using namespace std;
int kthSmallest(int arr[], int s, int e, int k){
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k ; i<=e; i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}
int main(){
int arr[] = {1,4,5,10,9,6,8};
cout<<kthSmallest(arr,0,6,4);
return 0;
}