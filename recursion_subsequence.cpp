#include<iostream>
#include<vector>
using namespace std;
void subsequence(string str, int i,string result, vector<string> &ans){
    if(i>=str.size()){
        ans.push_back(result);
        return;
    }
    subsequence(str,i+1,result+str[i],ans);
    subsequence(str,i+1,result,ans);
}
int main(){
    vector<string> ans;
    string result = "";
    string str = "abc";
    subsequence(str,0,result,ans);
    for(int i=0; i<ans.size(); i++){
        if(ans[i]==""){
            cout<<"\" \"";
        }
        cout<<ans[i]<<" ";
    }
    return 0;
}