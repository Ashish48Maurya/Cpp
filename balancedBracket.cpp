#include<iostream>
#include<stack>
using namespace std;

    bool isValid(string S){
        int n=S.size();
        stack<char> st;
        bool ans= true;    //Assume kar liya ki valid hi hoga
        for(int i=0; i<n; i++){
            if(S[i]=='(' or S[i]=='{' or S[i]=='['){
                st.push(S[i]);
            }
            else if(S[i]==')'){
                if(st.top()=='('){
                    st.pop();
                }
                else{
                     ans = false;
                     break;
                }
            }
            else if(S[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                }
                else{
                     ans = false;
                     break;
                }
            }
            else if(S[i]==']'){
                if(st.top()=='['){
                    st.pop();
                }
                else{
                     ans = false;
                     break;
                }
            }
        }    
      if(st.empty()){
        return true;
      }
      else{return ans;}
    }
int main(){
    // string S = "[{()}]";
    string S = "[{(}])";
    if(isValid(S)){
        cout<<"Valid String"<<endl;
    }
    else{
        cout<<"Invalid String"<<endl;
    }
return 0;
}