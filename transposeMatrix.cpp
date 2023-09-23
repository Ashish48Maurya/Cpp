//without using extra space;
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int> > vec(n , vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>vec[i][j];
        }
    }

    cout<<"Original Matrix"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(vec[i][j] , vec[j][i]);
        }
    }

    cout<<"Transpose Matrix"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<vec[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}