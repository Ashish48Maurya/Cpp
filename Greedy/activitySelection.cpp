#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int activitySelection(vector<int> start, vector<int> end){
    int N = start.size();
    vector<pair<int,int>> finalArray;
    for(int i=0; i<N; i++){
        finalArray.push_back({start[i],end[i]});
    }

    sort(finalArray.begin(),finalArray.end(),cmp);

    // Sorting Result
    // for(int i=0; i<N; i++){
    //     cout<<"{"<<finalArray[i].first<<","<<finalArray[i].second<<"}"<<endl;
    // }

    int count = 1;
    int endTime = finalArray[0].second;

    for(int i=1; i<N; i++){
        if(endTime<=finalArray[i].first){
            count++;
            endTime = finalArray[i].second;
        }
    }

    return count;
}

int main(){
    vector<int> start = {1,0,1,4,2,5,3,4};
    vector<int> end = {3,4,2,6,9,8,5,5};
    cout<<activitySelection(start,end)<<endl;
    return 0;
}