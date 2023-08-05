#include<iostream>          //0 1 0 1 0        zero (1,1) (1,3) (1,5) (2,2) (2,4) (3,1) (3,3) (4,2) (5,1)
using namespace std;        //1 0 1 0           pe aa raha hai-----> aur ye number ka jo sum hai usko 2
int main(){                 //0 1 0             se divide karne pe remainder 0 ho raha hai
                            //1 0
    cout<<"Enter the value of n: "<<endl;                      //0
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1-i; j++){

            if((i+j)%2 == 0 ){
                cout<<0<<" ";
            }

            else{
                cout<<1 <<" ";
            }
        }
        cout<<endl;
    }
   
    return 0;               
}