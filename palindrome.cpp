#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int a=s.length();
    bool check;
    for(int i=0; i<a; i++){
        if(s[i]!=s[a-1-i]){
        check=0;
        break;
        }
        else{check=1 ;}
    }
    if(check==1){
    cout<<"word is palindrome";}
    else{
    cout<<"word is not a palindrome";
    }
    return 0;
}