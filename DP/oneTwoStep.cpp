#include<iostream>
using namespace std;
int noOfWays(int n){
    //for 1step number of ways = 1;
    //For 2steps number of ways = 2;
    //For 3steps number of ways = 1+2; (i.e) summation of above 2;
    if(n==1 || n==2){
        return n;
    }
    return noOfWays(n-1)+noOfWays(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<noOfWays(n)<<endl;
    return 0;
}