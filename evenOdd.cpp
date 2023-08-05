// shift all even number at last position in the array
#include<iostream>
#include<vector>
using namespace std;
void sortEvenOddEle(vector<int> &v){
    int start = 0;
    int end = v.size()-1;
    while(start!=end){
    if((v[start]%2)==0 and (v[end]%2)!=0 ){
        swap(v[start],v[end]);
        start++;
        end--;
    }
    else if((v[start]%2)!=0){
        start++;
    }
    else{
        end--;
    }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int ele; cin>>ele;
        v.push_back(ele);
    }
    sortEvenOddEle(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}