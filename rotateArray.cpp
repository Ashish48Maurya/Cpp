// Firstly take transpose of a given 2D Array and then reverse every row

// Q-> Given a 2D Array rotate , it by 90 degree without using other vector
#include<iostream>
#include<vector>
using namespace std;
void rotate_2D_array(vector<vector<int>> &vec){
   int n = vec.size();
   for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            swap(vec[i][j] , vec[j][i]);
        }
    } 
    for(int i=0; i<n; i++){
        reverse(vec[i].begin() , vec[i].end());
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>vec[i][j];
        }
    }
    rotate_2D_array(vec);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}