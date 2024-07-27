#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v1 = {1,3,5,9,2,0};
    // vector<int> v2 = {5,3,0};
    vector<int> v2 = {3,3};
    unordered_map<int,int> umap;
    for(auto ele : v1){
        umap[ele]++;
    }

    int count = 0;
    for(auto ele:v2){
        for(auto it=umap.begin(); it!=umap.end(); it++){
            auto temp = umap.find(ele);
            if(temp!=umap.end()){
                count++;
                umap.erase(temp);
            }
        }
    }
    cout<<count<<endl;
    return 0;
}