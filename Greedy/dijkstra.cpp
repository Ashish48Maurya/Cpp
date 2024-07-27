#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>> adjList[], int V, int S){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(V);
    for(int i=0; i<V; i++) dis[i] = INT_MAX;
    dis[S] = 0;
    pq.push({0,S});

    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto i : adjList[node]){
            int nodeWeight = i[1];
            int nodeValue = i[0];

            if(weight+nodeWeight < dis[nodeValue]){
                dis[nodeValue] = weight+nodeWeight;
                pq.push({dis[nodeValue] , nodeValue,});
            }
        }
    }
    return dis;
}

int main(){
    int V = 3;  //No of Vertex(Node)
    int S = 0;  //Source Node
    vector<vector<int>> adjList[V];
    vector<int> v1{1,1}, v2{0,1}, v3{2,8}, v4{0,8}, v5{1,5}, v6{2,5};
    // vector<int> v1{1,1}, v2{0,1}, v3{2,3}, v4{0,3}, v5{1,5}, v6{2,5};
    adjList[0].push_back(v1);
    adjList[0].push_back(v3);
    adjList[1].push_back(v2);
    adjList[1].push_back(v6);
    adjList[2].push_back(v4);
    adjList[2].push_back(v5);

    vector<int> ans = dijkstra(adjList,V,S);
    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}