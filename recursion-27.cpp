//Maze-problem ----> College Wallah , Recursion-6;

#include<iostream>
using namespace std;

int f(int i, int j, int n, int m){
    if(i>=n or j>=m){
        return 0;
    }
    if(i==n-1 and j==m-1){
        return 1;
    }
    return f(i,j+1,n,m) + f(i+1,j,n,m);
}

int main(){
    int n,m;
    cout<<"Enter Number of rows and column , you want to built in your maze: ";
    cin>>n>>m;
    int ans = f(0,0,n,m);
    cout<<ans<<endl;
    return 0;
}