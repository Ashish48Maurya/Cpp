#include<iostream>
using namespace std;
char maxOccuring(string s){
char ch;
int arr[26] = {0} , index;
for(int i=0; i<s.size(); i++){
    ch = s[i];
    if(ch<='a' and ch>='z'){
        index = s[i] - 'a';
    }
    else{
        index = s[i] - 'A';
    }
    arr[index]++;
}
int maxI = -1, ans;
for(int i=0; i<26; i++){
    if(maxI<arr[i]){
        maxI = arr[i];
        ans=i;
    }
}
char finalAns = 'a'+ans;
return finalAns;
}
int main(){
cout<<"Enter the String: ";
string s;
cin>>s;
cout<<"Max Ocuuring character in a string is: "<<maxOccuring(s)<<endl;
return 0;
}