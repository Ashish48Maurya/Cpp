#include<iostream>
using namespace std;
    void Primesieve(int n)
       { int prime[100]={0};
        for(int i=2; i<=n; i++){
        if (prime[i]==0)    // prime == 0 -----> no. is not printed yet
       {for(int j=i*i ; j<=n ; j += i)
        prime[j]=1;  // prime == 1 --->  no. is printed
       }
        }
    for(int i=2; i<=n; i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }       //  cout<<endl;
    }
    int main(){
        int n;
        cin>>n;
        Primesieve(n);
    return 0;
}