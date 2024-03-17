#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>> graph, vector<int> &visited)
{
    cout<<node<<" ";
    visited[node] = 1;
    for(int i=0; i<7; i++){
        if(graph[node][i]==1 and visited[i]==0){
            DFS(i,graph,visited);
        }
    }
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 1, 1, 0, 0, 0},
                                 {1, 0, 1, 1, 0, 0, 0},
                                 {1, 1, 0, 1, 1, 0, 0},
                                 {1, 1, 1, 0, 1, 0, 0},
                                 {0, 0, 1, 1, 0, 1, 1},
                                 {0, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 0}};
    int sourceNode = 0;
    vector<int> visited(7, 0);

    DFS(sourceNode, graph, visited);
    return 0;
}