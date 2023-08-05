#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter the String"<<endl;
     string s; cin>>s;
    // 256 ASCii code raheta hai 
    //256 size ka array banaya jisme -1 hai
    vector<int> a(256,-1);
    int maxLen = 0,  start = -1;
    for(int i=0; i<s.length(); i++){
        if(a[s[i]]>start){
            start = a[s[i]];
        }
         a[s[i]] = i;
        maxLen = max(maxLen , i-start);
    }
    cout<<"Max length of Substring is"<<endl;
    cout<<maxLen<<endl;
    return 0;
}