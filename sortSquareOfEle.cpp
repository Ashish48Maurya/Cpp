// given a sorted array , make a sorted array of square of a element given in the array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sortSquareOfEle(vector<int> &v){
    int start = 0;
    int End = v.size()-1;
    vector<int> ans;
    while(start<End){
    if(abs(v[start])>abs(v[End])){
        int squ = (v[start]*v[start]);
        ans.push_back(squ);
        start++;
    }
    else{
        int squ1 = (v[End]*v[End]);
        ans.push_back(squ1);
        End--;
    }
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int n; cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int ele; cin>>ele;
        v.push_back(ele);
    }
    sortSquareOfEle(v);
    return 0;
}