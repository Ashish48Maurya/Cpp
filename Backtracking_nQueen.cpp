#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, int n, vector<vector<char>> maze) {
    // Check for Column
    for (int i = 0; i < n; i++) {
        if (maze[i][col] == 'Q') {
            return false;
        }
    }

    // Check for Row
    for (int i = 0; i < n; i++) {
        if (maze[row][i] == 'Q') {
            return false;
        }
    }

    // Check for Diagonal Attack
    int newRow = row - 1;
    int newColumn = col - 1;
    while (newColumn >= 0 && newRow >= 0) {
        if (maze[newRow][newColumn] == 'Q') {
            return false;
        }
        newRow--;
        newColumn--;
    }

    newRow = row - 1;
    newColumn = col + 1;
    while (newColumn < n && newRow >= 0) {
        if (maze[newRow][newColumn] == 'Q') {
            return false;
        }
        newRow--;
        newColumn++;
    }

    return true;
}


void nQueen(int row, int col, int n, vector<vector<char>> &maze){
    if(row==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<maze[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;
        return;
    }
    
    for(int column=0; column<n; column++){
        if(isSafe(row,column,n,maze)){
            maze[row][column] = 'Q';
            nQueen(row+1,column,n,maze);
            maze[row][column] = '-';
        }
    }
}

int main(){
    int n = 4;
    vector<vector<char>> maze(n,vector<char>(n,'-'));
    nQueen(0,0,n,maze);
    return 0;
}