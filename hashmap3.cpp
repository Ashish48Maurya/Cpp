//check whether strings are Anagram or not;
//e.g:  anagram,gram --> false    ,     triangle,integral ---> true;
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool anagramCheck(string &str1, string &str2){

if(str1.length()!=str2.length()){
    return false;
}

unordered_map<char,int> umap;
for(auto itr1: str1){
    umap[itr1]++;
}

for(auto itr2: str2){
    umap[itr2]--;
}

for(auto itr3: umap){
    if(itr3.second!=0){
        return false;
    }
}

return true;

}

int main(){
string str1,str2;
cin>>str1>>str2;

cout<<(anagramCheck(str1,str2)?"Anagram":"Not Anagram")<<endl;
return 0;
}