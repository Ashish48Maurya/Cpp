//Remove occurence of 'a' from string

//Method-1  Recursive Method
#include<iostream>
using namespace std;
string removeA(string str, int idx, int n){
if(idx==n){
    return "";
}
string curr  = "";
curr += str[idx];
string ans = ((str[idx]=='a')? "" : curr) + removeA(str,idx+1,n);
return ans;
}
int main(){
string str;
cout<<"Enter the String: ";
cin>>str;
int n = str.length();
cout<<removeA(str,0,n);
return 0;
}

//Method-2  iterative Method
// #include<iostream>
// using namespace std;
// int main(){
//  string str = "This is ASHISH";
//  string str1 = "";
//  int n = str.length();
//  for(int i=0; i<n; i++){
//     if(str[i] == 's' || str[i] == 'S' ){
//         continue;
//     }
//     else{
//         str1 += str[i];
//     }
//  }
//  cout<<str1;
//  return 0;
// }