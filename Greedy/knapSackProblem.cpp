#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int p;
    int w;
};

bool cmp(Item a, Item b){
    int first = a.p/a.w;
    int second = b.p/b.w;
    return first > second;
}

int findMaxProfit(Item arr[] ,int W, int n){ 
    sort(arr,arr+n,cmp);
    int weight = 0;
    int profit = 0;
    for(int i=0; i<n; i++){
        if(weight+arr[i].w <= W){
            weight += arr[i].w;
            profit += arr[i].p;
        }
        else{
            int remainingWeight = W-weight;
            profit += remainingWeight*(arr[i].p / arr[i].w);
        }
    }
    return profit;
}

int main(){
    Item arr[] = {{5,1},{10,3},{15,5},{7,4},{8,1},{9,3},{4,2}};
    int weight = 15;
    int n = 7;
    int ans = findMaxProfit(arr,weight,n);
    cout<<ans<<endl;
    return 0;
}