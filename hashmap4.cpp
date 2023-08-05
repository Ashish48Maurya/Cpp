// Check Whether 2 strings are one to one mapped or not
#include<iostream>
#include<unordered_map>
using namespace std;

bool OneToOne(string str1, string str2){
    unordered_map<char,char> up;
    for(int i=0; i<str1.length(); i++){
        if(up.find(str1[i]) != up.end()){
            //1st e.g  ==>  str1 = tmpop , str2 =  aeiou  
           // 2nd e.g  ==>  str1 = aeioa , str2 = tmpoa
            if(up[str1[i]]!=str2[i]){
                return false;
            }
        }
        else{
            up[str1[i]] = str2[i];
        }
    }
    up.clear();
    return true;
}

bool isOneToOneMapping(string str1, string str2){
    if(str1.length() != str2.length()){
        return false;
    }

    //Checking whether string 1 is one to one map or not with string 2;
    bool ans1 = OneToOne(str1,str2);

    //Checking whether string 2 is one to one map or not with string 1;
    bool ans2 = OneToOne(str2,str1);

    return ans1 and ans2;
    
}

int main(){
string str1 , str2;
cout<<"Enter 2-Strings: ";
cin>>str1>>str2;
cout<<(isOneToOneMapping(str1,str2) ? "Is One To One" : "Is not One To One")<<endl;
return 0;
}