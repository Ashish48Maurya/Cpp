//substring printing;
#include<iostream>
#include<string>
using namespace std;
void subseq(string s, string ans){
    if(s.size()==0){
    cout<<ans<<endl;
    return;
    }
    char ch=s[0];  string ros=s.substr(1);
    //Yes Choice
    subseq(ros, ans+ch);
    //No Choice
    subseq(ros, ans);
}

int main(){
   subseq("ABC" , " ");
    return 0;
}