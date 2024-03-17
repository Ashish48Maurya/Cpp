#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int graph[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                       {1, 0, 1, 1, 0, 0, 0},
                       {1, 1, 0, 1, 1, 0, 0},
                       {1, 1, 1, 0, 1, 0, 0},
                       {0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 1, 0, 0}};

    vector<int> visited(7,0);
    queue<int> ans;
    int sourecNode = 0;
    visited[sourecNode] = 1;
    ans.push(sourecNode);

    while(!ans.empty()){
        int node = ans.front();
        cout<<node<<" ";
        ans.pop();
        for(int i=0; i<7; i++){
            if(graph[node][i]==1 and visited[i]==0){
                ans.push(i);
                visited[i] = 1;
            }
        }
    }
    return 0;
}