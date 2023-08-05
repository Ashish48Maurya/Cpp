#include<iostream>
#include<vector>
using namespace std;
int main(){
int n;
cout<<"Enter the no. of element in array: ";
cin>>n;
vector<int> v(n);
for(int i=0; i<n; i++){
    cin>>v[i];
}
int larElement = -1;
for(int i=0; i<n; i++){
if(v[i]>larElement){
    larElement=v[i];
}}
cout<<larElement<<endl;
vector<int> freq(larElement,0);
for(int i=0; i<n; i++){
    freq[v[i]]++;
}
int q;
cout<<"Enter the No. of Queries: ";
cin>>q;
while(q>0){
    int queryElement; cin>>queryElement;
    cout<<queryElement<<" is present "<<freq[queryElement]<<" times in array "<<endl;
}
return 0;
}