#include<iostream>            //1 2 3 4 5
using namespace std;          //1 2 3 4
int main(){                   //1 2 3
                              //1 2
                              //1
        
        int n;
        cin>>n;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n+1-i; j++){
                cout<<j<<" ";
            }
           
            cout<<endl;
        }

    return 0;
}