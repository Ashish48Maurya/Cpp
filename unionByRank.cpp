#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    vector<int> rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);

        for(int i=0; i<=n; i++) parent[i]=i;
    }

    int findParent(int node){
    if(parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]);
    }


    void disjointSet(int u, int v){
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }
        else if(rank[parent_v] > rank[parent_u]){
            parent[parent_u] = parent_v;
        }
        else{
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
    }
};
int main(){
    DisjointSet ds(7);
    ds.disjointSet(1,2);
    ds.disjointSet(2,3);
    ds.disjointSet(4,5);
    ds.disjointSet(6,7);
    ds.disjointSet(5,6);

    if(ds.findParent(1) == ds.findParent(4)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }

    ds.disjointSet(3,7);
    if(ds.findParent(1) == ds.findParent(4)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    return 0;
}