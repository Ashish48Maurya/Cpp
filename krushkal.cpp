#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int pU = findParent(u);
        int pV = findParent(v);
        if(size[pU] > size[pV]){
            parent[pV] = pU;
            size[pU] += size[pV];
        }
        else{
            parent[pU] = pV;
            size[pV] += size[pU];
        }
    }
};
int krushkal(vector<vector<int>> adj[], int V){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0; i<V; i++){
        for(auto it : adj[i]){
            int node = i;
            int adjNode = it[0];
            int weight = it[1];
            edges.push_back({weight, {node,adjNode}});
        }
    }
    sort(edges.begin(), edges.end());

    // for(auto it : edges){
    //     cout<<"Weight: "<<it.first<<" Node: "<<it.second.first<<" AdjNode: "<<it.second.second<<endl;
    // }

    DisjointSet ds(V);
    int mstWeight = 0;
    for(auto it: edges){
        int node = it.second.first;
        int adjNode = it.second.second;
        int weight = it.first;
        if(ds.findParent(node)!=ds.findParent(adjNode)){
            mstWeight += weight;
            ds.unionBySize(node,adjNode);
        }
    }
    return mstWeight;
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

    int ans = krushkal(adjList,V);
    cout<<"MST: "<<ans<<endl;
    return 0;
}