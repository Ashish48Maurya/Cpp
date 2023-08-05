#include<iostream>
using namespace std;
 int kadane(int A[], int n){
        int currsum=0, maxsum=0;
        for(int i=0; i<n; i++){
            currsum += A[i];
            if(currsum<0){currsum=0;}
            if(currsum>maxsum){maxsum=currsum;}
            return maxsum;
        }
    }
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
   int wrapsum, nonwrapsum;
   nonwrapsum=kadane(A,n);
   int totalsum=0;
   for(int i=0; i<n; i++){
    totalsum += A[i];
    A[i]= -A[i] ;
   }
   wrapsum= totalsum - (-kadane(A,n));
   cout<<max(wrapsum,nonwrapsum)<<endl;
    return 0;
}