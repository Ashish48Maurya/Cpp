#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<int>> adjList, int S, int V){
    vector<int> dist(V,1e8);
    dist[S] = 0;
    for(int i=0; i<V-1; i++){
        for(auto element : adjList){
            int u = element[0]; //from
            int v = element[1]; //to
            int w = element[2]; //cost required for travelling from u to v

            if(dist[u]!=1e8 and dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }

    //to detect cycle traverse one more time
    for(auto element:adjList){
       int u = element[0]; //from
       int v = element[1]; //to
       int w = element[2]; //cost required for travelling from u to v
       if(dist[u]!=1e8 and dist[u]+w < dist[v]){
           return {-1};
       }
    }
    return dist;
}

int main(){
    int V = 6;  //No of Vertex(Node)
    int S = 0;
    vector<vector<int>> adjList = {{3,2,6},{5,3,1},{0,1,5},{1,5,-3},{1,2,-2},{3,4,-2},{2,4,3}};
    vector<int> ans = bellmanFord(adjList,S,V);
    for(auto i : ans){
       cout<<i<<" ";
    }
    return 0;
}