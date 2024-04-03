#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {1,3,6,7,9,4,3,6};
    unordered_map<int,int> umap;
    for(auto ele : v){
        umap[ele]++;
    }

    int ans = -1;
    for(auto ele: v){
        auto temp = umap.find(ele);
        if(temp->first > 1){
            ans = temp->first;
            break;
        }
    }
    cout<<"First Repeating Element is: "<<ans<<endl;
    return 0;
}