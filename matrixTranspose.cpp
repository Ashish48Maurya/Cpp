#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n,m;
    int a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int arr[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            a[i][j] = arr[j][i];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}