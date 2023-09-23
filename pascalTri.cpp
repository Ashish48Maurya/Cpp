#include<iostream>
#include<vector>
using namespace std;

void pascalTri(int n){

    vector<vector<int>> pascal(n);

    for(int i=0; i<n; i++){
            pascal[i].resize(i+1);
        for(int j=0; j<pascal[i].size(); j++){
            if(j==0 or j==i){
                pascal[i][j] = 1;
            }
            else{
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
        }
    }

    for(int i=0; i<pascal.size(); i++){
        for(int j=0; j<pascal[i].size(); j++){
            cout<<pascal[i][j]<<" ";
        }cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    pascalTri(n);
return 0;
}