#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int prims(vector<vector<int>> adj[], int V){
    vector<int> visited(V,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int sum = 0;
    pq.push({0,0}); // Here second Element is Representing Node(Source Node) , You Can Take any Node as a Source Node;

    while(!pq.empty()){
        int node_weight = pq.top().first;
        int node_value = pq.top().second;
        pq.pop();
        if(visited[node_value]==1) continue;
        visited[node_value] = 1;
        sum += node_weight;

        for(auto it : adj[node_value]){
            int nodeValue = it[0];
            int nodeWeight = it[1];
            if(visited[nodeValue]==0){
                pq.push({nodeWeight,nodeValue});
            }
        }
    }
    return sum;
}

int main(){
    int V = 3;  //No of Vertex(Node)
    vector<vector<int>> adjList[V];
    vector<int> v1{1,1}, v2{0,1}, v3{2,8}, v4{0,8}, v5{1,5}, v6{2,5};
    adjList[0].push_back(v1);
    adjList[0].push_back(v3);
    adjList[1].push_back(v2);
    adjList[1].push_back(v6);
    adjList[2].push_back(v4);
    adjList[2].push_back(v5);

    int ans = prims(adjList,V);
    cout<<ans<<endl;
    return 0;
}