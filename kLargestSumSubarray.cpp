// Kth Largest Sum Subarray
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
priority_queue<int , vector<int> , greater<int>> p;
int arr[] = {1,2,3};
int sum = 0;
for(int i=0; i<3; i++){
    for(int j=i; j<3; j++){
        sum  += arr[j];
        p.push(sum);
    }
}
cout<<"Enter the value of K: ";
int k; cin>>k;
int size = p.size();
for(int i=0; i<(size-k); i++){
    p.pop();
}
cout<<"Your ans is: "<<p.top()<<endl;
return 0;
}