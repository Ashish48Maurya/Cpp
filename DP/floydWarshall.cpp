#include<bits/stdc++.h>
using namespace std;

void floydW(vector<vector<int>> matrix){
    int V = matrix.size(); //No. Of Nodes
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(matrix[i][j] == -1){
                matrix[i][j]=1e8;
            }
        }
    }

    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            int ans = matrix[i][j]==1e8 ? -1:matrix[i][j];
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> matrix = {{0,8,-1,1},{-1,0,1,-1},{4,-1,0,-1},{-1,2,9,0}};
    floydW(matrix);
    return 0;
}