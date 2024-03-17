#include<iostream>
#include<vector>
using namespace std;
int main(){
    int noOfNodes;
    cin>>noOfNodes;
    vector<int> adjList[noOfNodes];

    for(int i=0;i<noOfNodes; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(auto i:adjList){
        for(auto j : i){
            cout<<j<<" ";
        }
    }
    return 0;
}