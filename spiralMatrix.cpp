#include<iostream>
#include<vector>
using namespace std;

void spiralMatrix(vector<vector<int>> &v){
    int top_ptr  = 0;
    int bottom_ptr = v.size()-1; // OR n-1
    int left_ptr = 0;
    int right_ptr = v[0].size()-1; // OR m-1   if n,n is also passed as an a argument

    int itr = 0;

    while (top_ptr<=bottom_ptr and right_ptr>=left_ptr)
    {
        if(itr==0){
            for(int col=left_ptr ; col<=right_ptr; col++){
                cout<<v[top_ptr][col]<<" ";
            }
            top_ptr++;
        }
        else if(itr==1){
            for(int row=top_ptr; row<=bottom_ptr; row++){
                cout<<v[row][right_ptr]<<" ";
            }
            right_ptr--;
        }
        else if(itr==2){
            for(int col=right_ptr; col>=left_ptr; col--){
                cout<<v[bottom_ptr][col]<<" ";
            }
            bottom_ptr--;
        }
        else{
            for(int row=bottom_ptr; row>=top_ptr; row--){
                cout<<v[row][left_ptr]<<" ";
            }
            left_ptr++;
        }
        itr = (itr+1)%4; // 0 1 2 3 ,after '3' itr again becomes 1 because of modulo operator
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> vec(n,vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>vec[i][j];
        }
    }

    spiralMatrix(vec);
    return 0;
}