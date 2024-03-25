#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct Job
{
    int id;
    int deadLine;   
    int profit;
};

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

vector<int> findProfit(Job arr[], int N){
    sort(arr,arr+N,cmp);
    int maxDeadLine = INT_MIN;
    for(int i=0; i<N; i++){
        maxDeadLine = max(maxDeadLine,arr[i].deadLine);
    }

    int count = 0;
    int profit = 0;
    vector<int> schedule(maxDeadLine+1,-1);

    for(int i=0; i<N; i++){
        int jobDeadLine = arr[i].deadLine;
        int jobId = arr[i].id;
        int jobProfit = arr[i].profit;

        for(int k=jobDeadLine; k>0; k--){
            if(schedule[k]==-1){
                count++;
                schedule[k] = jobId;
                profit += jobProfit;
                break;
            }
        }
    }

    vector<int> ans;
    ans.push_back(count);
    ans.push_back(profit);
    return ans;
}


int main(){
    Job arr[] = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    int N = 4;
    vector<int> ans = findProfit(arr,N);
    cout<<"No. Of Jobs: "<<ans[0]<<", Job profit: "<<ans[1]<<endl;
    return 0;
}