#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    bool flag=0;
    
    for(int i=2; i*i<n; i++){
        if (n%2 == 0)
        {
           cout<<"The number is not prime"<<endl;
           flag=1;
           break;
        }
        
    }
    if(flag==0){
        cout<<"prime"<<endl;
    }


    return 0;
}