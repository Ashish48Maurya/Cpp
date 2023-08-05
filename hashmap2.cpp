//check whether strings in a given vector is made equal by  exchanging(you can exchange character n no. of times) character of one string with another;
//eg: {"collegeeee","coll","collegg"}    ---->   Yes
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool checkstring(vector<string> &v){

int n = v.size();

unordered_map<char,int> umap;
for(auto str:v){
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        umap[ch]++;
    }
}

for(auto itr:umap){
    if(itr.second%n != 0){
       return false;
    }
    
}

return true;

}

int main(){
int n;
cout<<"No. of strings want: ";
cin>>n;
vector<string> vec(n);
for(int i=0; i<n; i++){
    cin>>vec[i];
}

cout<<(checkstring(vec)? "Yes":"No")<<endl;

return 0;
}