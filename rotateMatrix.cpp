// {1,2,3}      Rotated by 90deg        {7,4,1}
// {4,5,6}             ==>              {8,5,2}
// {7,8,9}                              {9,6,3}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateMatrix(vector<vector<int>> &v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<i; j++){
            swap(v[i][j] , v[j][i]);
        }
    }

    for(int i=0; i<v.size(); i++){
        reverse(v[i].begin() , v[i].end());
    }

    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n , vector<int> (m));
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>vec[i][j];
        }
     }

     rotateMatrix(vec);

    return 0;
}