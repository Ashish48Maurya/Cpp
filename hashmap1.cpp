//Give the sum of elements which is repeating in the given array;
//e.g: {1,2,3,1,2,1,3}  ---->  ans = 1+2+3 = 6;

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
int n;
cout<<"Give n: ";
cin>>n;
vector<int> vec(n);
cout<<"Give input: ";
for(int i=0; i<n; i++){
    cin>>vec[i];
}

unordered_map<int,int> umap;
for(auto itr:vec){
    umap[itr]++;
}

int ans = 0;
for(auto itr1:umap){
    cout<<itr1.first<<"->"<<itr1.second<<endl;
    if(itr1.second > 1){
        ans+=itr1.first;
    }
}

cout<<"Ans: "<<ans<<endl;

return 0;
}