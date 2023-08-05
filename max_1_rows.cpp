//Given an 2D boolean Array which is sorted also rerurn the row number containing max number of 1s


// Hint : Sorted ka faidaa uthao
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxOnesRows(vector<vector<int> >&vec){
 int maxOnesInRows = INT_MIN;
 int maximun_1_containing_row = -1;
 int column = vec[0].size();
 for(int i=0; i<vec.size(); i++){
    for(int j=0; j<vec[i].size();j++){
        if(vec[i][j]==1){
            int numberOfOnes = column-j;
            if(numberOfOnes>maxOnesInRows){

            maxOnesInRows = numberOfOnes;
            maximun_1_containing_row = i;

            }
            break;
        }
    }
 }
return maximun_1_containing_row;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(m));
    // n--> Rows , m--> Columns
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>vec[i][j];
        }
    }
    int ans = maxOnesRows(vec);
    cout<<ans<<endl;
    return 0;
}