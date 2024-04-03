#include<bits/stdc++.h>
using namespace std;

bool isPresent(vector<int> v,int target){
    unordered_map<int,int> umap;
    for(auto ele : v){
        umap[ele]++;
    }

    for(auto it=umap.begin(); it!=umap.end(); it++){
        int key = it->first;
        int value = it->second;

        int findEle = target-key;
        if(findEle==key){
            if(value > 1){
                return true;
            }
            else{
                return false;
            }
        }

        if(umap.find(findEle) != umap.end()){
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> v = {1,5,9,2,4,8};
    // int target = 11;
    int target = 20;
    cout<<isPresent(v,target)<<endl;
    return 0;
}