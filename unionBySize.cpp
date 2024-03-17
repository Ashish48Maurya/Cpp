#include<iostream>
#include<vector>
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
int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.findParent(1) == ds.findParent(4)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }

    ds.unionBySize(3,7);
    if(ds.findParent(1) == ds.findParent(4)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    return 0;
}