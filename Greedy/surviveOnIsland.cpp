#include<iostream>
#include<vector>
using namespace std;

int purchaseCount(int N,int M, int S){
    int sundays = S/7;
    int workingDays = S - sundays;
    int noOfPacketsRequired = S*M;
    int count = 0;

    if(noOfPacketsRequired%N == 0){
        count = noOfPacketsRequired/N;
    }
    else{
        count = noOfPacketsRequired/N + 1;
    }

    if(count <= workingDays){
        return count;
    }
    else{
        return -1;  // Case: N=1, M=1, S=10;    ==>  workingDays=9 (1 Sunday) , count = 10; means you have to buy 1 packet per day for 10 days in order to survive, but shop will remain close on Sunday 
    }
}

int main(){
    int M = 2;
    int N = 16;
    int S = 10;
    int ans = purchaseCount(N,M,S);
    cout<<"No. of Purchase: "<<ans<<endl;
    return 0;
}