#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> v2 = {2,1,4,3,9,6};
    vector<int> ans;
    map<int,int> mp; //map stores the element in sorted Manner
    for(auto ele : v1){
        mp[ele]++;
    }

    for(auto ele:v2){
        if(mp.find(ele)!=mp.end()){
            auto temp = mp.find(ele);
            int count = temp->second;
            vector<int> v(count,ele);
            ans.insert(ans.end(),v.begin(),v.end());
            // v.clear();
            mp.erase(temp);
        }
    }
    
    if(mp.size() > 0){
        for(auto ele : mp){
        int count = ele.second;
        int value = ele.first;
        vector<int> temp(count,value);
        ans.insert(ans.end(),temp.begin(),temp.end());
        }
    } 

    for(auto ele : ans){
        cout<<ele<<" ";
    }
    return 0;
}