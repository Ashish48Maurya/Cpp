#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i, int j, vector<vector<char>> board){
    if(i-1>=0 and j-2>=0 and board[i-1][j-2] == 'K') return false;
    if(i-1>=0 and j+2<board[i].size() and board[i-1][j+2] == 'K') return false;
    if(i-2>=0 and j-1>=0 and board[i-2][j-1] == 'K') return false;
    if(i-2>=0 and j+1<board[i].size() and board[i-2][j+1] == 'K') return false;
    return true;
}

void knights(int r, int c, int m, int n, vector<vector<char>> &board, int K){
    if(K==0){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;
        return;
    }
    if(r==m){
        return;
    }
    for(int row=r ; row<m; row++){
        for(int column=(row == r ? c : 0); column<n; column++){
            if(isSafe(row,column,board)){
            board[row][column] = 'K';
            knights(row,column+1,m,n,board,K-1);
            board[row][column] = '.';
            }
        }
    }
}

int main(){
    cout<<endl;
    int m = 3;
    int n = 3;
    int row = 0;
    int column = 0;
    int no_of_knights = 4;
    vector<vector<char>> board(m,vector<char>(n,'.'));
    knights(row,column,m,n,board,no_of_knights);
    return 0;
}