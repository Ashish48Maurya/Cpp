#include<iostream>
using namespace std;

bool isPalindrome(string str , int left, int right){
    if(left>=right){
        return true;
    }
    if(str[left]!=str[right]){
        return false;
    }
    isPalindrome(str,left+1,right-1);
}

int main(){
    string str;
    cin>>str;
    int size  = str.length();
    bool ans = isPalindrome(str,0,size-1);
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    // isPalindrome(string,leftPointer,rightPointer);
    return 0;
}