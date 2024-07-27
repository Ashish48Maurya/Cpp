#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int prec(char ch){
    if(ch=='^'){return 3;}
    else if(ch=='*' or ch=='/'){return 2;}
    else if(ch=='+' or ch=='-'){return 1;}
    else{return -1;}
}
string infixToPostfix(string s){
    stack<char> st;
    string res;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a' and s[i]<='z'){
           res += s[i];
        }
        // if(s[i]>='A' and s[i]<='Z'){
        //      res += s[i];
        // }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() and st.top()!='('){
              res += st.top();
              st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() and prec(s[i])<=prec(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    return res;
}

int main(){
    string s = "(a-b/c)*(a/k-l)";
    cout<<infixToPostfix(s)<<endl;
    return 0;
}